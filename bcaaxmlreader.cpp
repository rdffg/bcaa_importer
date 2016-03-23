#include "bcaaxmlreader.h"
#include "DataAdvice.hxx"
#include <memory>
#include <QDebug>
#include <ios>
#include "QDjango.h"
#include "model/model.h"
#include "saveerror.h"
#include "QSqlDatabase"


BcaaXmlReader::BcaaXmlReader(QString filePath, QObject *parent) : QObject(parent)
  , continueJob(true)
  , m_jurisdictiontypes(std::map<model::minortaxing::JurisdictionType::TaxingJurisdictionType, std::unique_ptr<model::minortaxing::JurisdictionType> >())
  , m_valueTypes(std::map<model::PropertyClassValueType::ValueType, std::unique_ptr<model::PropertyClassValueType> >())
  , m_filePath(filePath)
{
}

void BcaaXmlReader::loadMinorTaxingJurisdictions() {
    auto meta = QMetaEnum::fromType<model::minortaxing::JurisdictionType::TaxingJurisdictionType>();
    for (int i = 0; i < meta.keyCount(); ++i) {
        auto jurisdiction_type = std::make_unique<model::minortaxing::JurisdictionType>();
        jurisdiction_type->setType(static_cast<model::minortaxing::JurisdictionType::TaxingJurisdictionType>(meta.value(i)));
        jurisdiction_type->setDescription(meta.key(i));
        if (!jurisdiction_type->save()) {
            QString err = QString("Failed to insert minor taxing jurisdiction type: ") + QDjango::database().lastError().text();
            throw SaveError(err);
        }
        m_jurisdictiontypes.insert(std::make_pair(jurisdiction_type->type(), std::move(jurisdiction_type)));
    }
}

void BcaaXmlReader::loadPropertyClassValueTypes() {
    auto meta = QMetaEnum::fromType<model::PropertyClassValueType::ValueType>();
    for (int i = 0; i < meta.keyCount(); ++i) {
        auto valueType = model::PropertyClassValueType::fromValueType(
                    static_cast<model::PropertyClassValueType::ValueType>(meta.value(i)));
        if (!valueType->save())
        {
            QString err = QString("Failed to insert Property Class Value Type: ") + QDjango::database().lastError().text();
            throw SaveError(err);
        }
        m_valueTypes.insert(std::make_pair(valueType->type(), std::move(valueType)));
    }
}

void BcaaXmlReader::import() {
    continueJob = true;
    std::unique_ptr<dataadvice::DataAdvice> da;
    xml_schema::properties props;
    emit message(QString("Opening file ") + m_filePath);
    //props.no_namespace_schema_location("DataAdvice.xsd");
    props.schema_location("http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd", "DataAdvice.xsd");
    try {
        da = dataadvice::DataAdvice_ (m_filePath.toStdString(), 0 ,props);
    } catch (const xml_schema::exception &e) {
        // fixme
        std::stringstream stream;
        stream << "error:";
        stream << e;
        QString s = QString::fromStdString(stream.str());
        qDebug() << "Failed to parse XML file: " << e.what() << s;
        QString msg = "Failed to parse XML file: ";
        msg += e.what();
        emit message(msg);
        emit finished();
        return;
    }

    auto db = QSqlDatabase::addDatabase(QDjango::database().driverName(), "conn_from_thread");
    db.setDatabaseName(QDjango::database().databaseName());
    db.open();
    QDjango::setDatabase(db);
    // FIXME: don't drop tables in production!
    QDjango::dropTables();
    if (!QDjango::createTables())
    {
        emit message(QString("Failed to create tables."));
        QDjango::database().close();
        return;
    }

    try {

            // FIXME re-enable transactions
            //QDjango::database().transaction();
            loadMinorTaxingJurisdictions();
            loadPropertyClassValueTypes();

            qDebug() << "Opened XML file...";
            emit message("Successfully opened the XML file");
            dataadvice::DataAdvice::AssessmentAreas_optional aac = da.get()->AssessmentAreas();
            if (aac.present()) {
                    dataadvice::DataAdvice::AssessmentAreas_type dat = aac.get();
                    // assessment area
                    auto aa_seq = dat.AssessmentArea();
                    for (auto &&a : aa_seq) {
                            auto aamodel = std::unique_ptr<model::AssessmentArea>(model::AssessmentArea::fromXml(a));
                            if (!aamodel->save()) {
                                    QString err = QString("Failed to save Assessment Area: ") + QDjango::database().lastError().text();
                                    throw SaveError(err);
                            }

                            emit message(QString("Found Assessment Area ") + QString::fromStdString(a.AssessmentAreaCode()));

                            // jurisdiction
                            auto juris_seq = a.Jurisdictions().get().Jurisdiction();
                            for (auto &&juris: juris_seq) {
                                    auto juris_model = std::unique_ptr<model::Jurisdiction>(model::Jurisdiction::fromXml(juris));
                                    emit message(QString("Found Jurisdiction ")
                                                 + juris_model->description());
                                    juris_model->setAssessmentArea(aamodel.get());
                                    if (!juris_model->save()) {
                                            QString err = QString("Failed to save Jurisdiction: ") + QDjango::database().lastError().text();
                                            throw SaveError(err);

                                    }

                                    // folio
                                    auto folio_seq = juris.FolioRecords().get().FolioRecord();
                                    for (auto &&folio : folio_seq) {
                                        //QThread::msleep(500);
                                        if (!continueJob) {
                                            throw SaveError("Job cancelled");
                                        }
                                            auto foliomodel = std::unique_ptr<model::Folio>(model::Folio::fromXml(folio));
                                            foliomodel->setJurisdiction(juris_model.get());
                                            if (!foliomodel->save()) {
                                                    QString err = QString("Failed to save Folio: ") + QDjango::database().lastError().text();
                                                    throw SaveError(err);

                                            }
                                            emit message(QString(" - ") + foliomodel->rollNumber());
                                            emit folioSaved();

                                            // Folio addresses
                                            if (folio.FolioAddresses().present()) {
                                                    auto addr_seq = folio.FolioAddresses().get().FolioAddress();
                                                    for (auto &&addr: addr_seq) {
                                                            auto addrmodel = std::unique_ptr<model::FolioAddress>(model::FolioAddress::fromXml(addr));
                                                            addrmodel->setFolio(foliomodel.get());
                                                            if (!addrmodel->save()) {
                                                                    QString err = QString("Failed to save Folio Address: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }
                                            }

                                            // Folio Description
                                            if (folio.FolioDescription().present()) {
                                                auto descr = model::FolioDescription::fromXml(folio.FolioDescription().get());
                                            }

                                            // ownership groups
                                            auto own_groups_seq = folio.OwnershipGroups()->OwnershipGroup();
                                            for (auto&& og : own_groups_seq) {
                                                    auto groupmodel = std::unique_ptr<model::OwnershipGroup>(model::OwnershipGroup::fromXml(og));
                                                    groupmodel->setFolio(foliomodel.get());
                                                    if (!groupmodel->save()) {
                                                            QString err = QString("Failed to save OwnershipGroup: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                    }

                                                    // owners
                                                    for (auto &&owner : og.Owners().get().Owner()) {
                                                            auto ownermodel = std::unique_ptr<model::Owner>(model::Owner::fromXml(owner));
                                                            ownermodel->setOwnershipGroup(groupmodel.get());
                                                            if (!ownermodel->save()) {
                                                                    QString err = QString("Failed to save Owner: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }

                                                    // mailing address
                                                    if (og.MailingAddress().present()) {
                                                            auto mamodel = std::unique_ptr<model::MailingAddress>(model::MailingAddress::fromXml(og.MailingAddress().get()));
                                                            mamodel->setOwnershipGroup(groupmodel.get());
                                                            if (!mamodel->save()) {
                                                                    QString err = QString("failed to save mailing address: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }

                                                    // formatted mailing address
                                                    if (og.FormattedMailingAddress().present()) {
                                                            auto fma = std::unique_ptr<model::FormattedMailingAddress>(model::FormattedMailingAddress::fromXml(og.FormattedMailingAddress().get()));
                                                            fma->setOwnershipGroup(groupmodel.get());
                                                            if (!fma->save()) {
                                                                    QString err = QString("Failed to save formatted mailing address: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }
                                            }

                                            // minor taxings
                                            if (folio.MinorTaxing().present()) {
                                                // general service
                                                if (folio.MinorTaxing().get().GeneralServices().present()) {
                                                        auto gs = folio.MinorTaxing().get().GeneralServices().get();
                                                        processMinorTaxJurisdiction(gs, foliomodel, model::minortaxing::JurisdictionType::GeneralService);
                                                }
                                                // island trusts
                                                if (folio.MinorTaxing().get().IslandsTrusts().present()) {
                                                        auto it = folio.MinorTaxing().get().IslandsTrusts().get();
                                                        processMinorTaxJurisdiction(it, foliomodel, model::minortaxing::JurisdictionType::IslandTrust);
                                                }

                                                // electoral areas
                                                if (folio.MinorTaxing().get().ElectoralAreas().present()) {
                                                        auto ea_seq = folio.MinorTaxing().get().ElectoralAreas().get().MinorTaxingJurisdiction();
                                                        for (auto ea : ea_seq)
                                                        {
                                                                processMinorTaxJurisdiction(ea, foliomodel, model::minortaxing::JurisdictionType::ElectoralArea);
                                                        }
                                                }

                                                // Defined
                                                if (folio.MinorTaxing().get().Defined().present())
                                                {
                                                        auto de_seq = folio.MinorTaxing().get().Defined().get().MinorTaxingJurisdiction();
                                                        for (auto &&defined: de_seq)
                                                        {
                                                                processMinorTaxJurisdiction(defined, foliomodel, model::minortaxing::JurisdictionType::Defined);
                                                        }
                                                }

                                                // Specified Regional
                                                if (folio.MinorTaxing().get().SpecifiedRegional().present()) {
                                                        auto sr_seq = folio.MinorTaxing().get().SpecifiedRegional().get().MinorTaxingJurisdiction();
                                                        for (auto &&sr: sr_seq) {
                                                                processMinorTaxJurisdiction(sr, foliomodel, model::minortaxing::JurisdictionType::SpecifiedRegional);
                                                        }
                                                }

                                                // Service Areas
                                                if (folio.MinorTaxing().get().ServiceAreas().present())
                                                {
                                                        auto sa_seq = folio.MinorTaxing().get().ServiceAreas().get().MinorTaxingJurisdiction();
                                                        for (auto &&sa: sa_seq) {
                                                                processMinorTaxJurisdiction(sa, foliomodel, model::minortaxing::JurisdictionType::ServiceArea);
                                                        }
                                                }

                                                // Specified Municipal
                                                if (folio.MinorTaxing().get().SpecifiedMunicipal().present()) {
                                                        auto sm_seq = folio.MinorTaxing().get().SpecifiedMunicipal().get().MinorTaxingJurisdiction();
                                                        for (auto &&sm: sm_seq) {
                                                                processMinorTaxJurisdiction(sm, foliomodel, model::minortaxing::JurisdictionType::SpecifiedMunicipal);
                                                        }
                                                }

                                                // Improvement Districts
                                                if (folio.MinorTaxing().get().ImprovementDistricts().present()) {
                                                        auto id_seq = folio.MinorTaxing().get().ImprovementDistricts().get().MinorTaxingJurisdiction();
                                                        for (auto &&id : id_seq) {
                                                                processMinorTaxJurisdiction(id, foliomodel, model::minortaxing::JurisdictionType::ImprovementDistrict);
                                                        }
                                                }

                                                // Local Areas
                                                if (folio.MinorTaxing().get().LocalAreas().present()) {
                                                        auto la_seq = folio.MinorTaxing().get().LocalAreas().get().MinorTaxingJurisdiction();
                                                        for (auto &&la: la_seq) {
                                                                processMinorTaxJurisdiction(la, foliomodel, model::minortaxing::JurisdictionType::LocalArea);
                                                        }
                                                }
                                            }

                                            // Sales
                                            if (folio.Sales().present())
                                            {
                                                auto sale_seq = folio.Sales().get().Sale();
                                                for (auto &&sale : sale_seq)
                                                {
                                                    auto salemodel = model::Sale::fromXml(sale);
                                                    salemodel->setFolio(foliomodel.get());
                                                    if (!salemodel->save())
                                                    {
                                                        QString err = QString("Failed to save property sale: ") + QDjango::database().lastError().text();
                                                        throw SaveError(err);
                                                    }
                                                }
                                            }

                                            // Farm
                                            if (folio.Farms().present())
                                            {
                                                auto farm_seq = folio.Farms().get().Farm();
                                                for (auto &&farm: farm_seq)
                                                {
                                                    for (auto &&farmnumber: farm.FarmNumber())
                                                    {
                                                        auto farmmodel = model::Farm::fromXml(farmnumber);
                                                        farmmodel->setFolio(foliomodel.get());
                                                        if (!farmmodel->save())
                                                        {
                                                            QString err = QString("Failed to save property farm: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                        }
                                                    }
                                                }
                                            }

                                            // tax exempt property class
                                            if (folio.Values().present())
                                            {
                                                if (folio.Values().get().TaxExemptValues().present())
                                                {
                                                    auto te_seq = folio.Values().get().TaxExemptValues().get().TaxExemptPropertyClassValues();
                                                    for (auto &&tevalue: te_seq)
                                                    {
                                                        auto temodel = model::TaxExemptPropertyClassValue::fromXml(tevalue);
                                                        temodel->setFolio(foliomodel.get());
                                                        if (!temodel->save())
                                                        {
                                                            QString err = QString("Failed to save tax exempt value: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                        }
                                                    }
                                                }
                                                if (folio.Values().get().BCTransitValues().present())
                                                {
                                                    auto transit_seq = folio.Values().get().BCTransitValues().get().PropertyClassValues();
                                                    for (auto &&bct : transit_seq)
                                                    {
                                                        auto transitmodel = model::PropertyClassValue::fromXml(bct);
                                                        transitmodel->setFolio(foliomodel.get());
                                                        if (bct.GrossValues().present())
                                                            transitmodel->setGrossValues(model::Valuation::fromXml(bct.GrossValues().get()).get());
                                                        auto valueType = model::PropertyClassValueType::fromValueType(model::PropertyClassValueType::BCTransit);
                                                        //auto valueType = m_valueTypes[model::PropertyClassValueType::ValueType::BCTransit].get();
                                                        transitmodel->setValueType(std::move(valueType));
                                                        if (!transitmodel->save())
                                                        {
                                                            QString err = QString("Failed to save BC transit value: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                        }
                                                    }
                                                }
                                                if (folio.Values().get().GeneralValues().present())
                                                {
                                                    auto general_seq = folio.Values().get().GeneralValues().get().PropertyClassValues();
                                                    for (auto &&general :  general_seq) {
                                                        auto value = model::PropertyClassValue::fromXml(general);
                                                        value->setFolio(foliomodel.get());
                                                        auto valueType = model::PropertyClassValueType::fromValueType(model::PropertyClassValueType::General);
                                                        value->setValueType(std::move(valueType));
                                                        if (!value->save())
                                                        {
                                                            QString err = QString("Failed to save General Value: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                        }
                                                    }
                                                }
                                                if (folio.Values().get().SchoolValues().present()) {
                                                    auto school_seq = folio.Values().get().SchoolValues().get().PropertyClassValues();
                                                    for (auto &&school: school_seq) {
                                                        auto schoolmodel = model::PropertyClassValue::fromXml(school);
                                                        schoolmodel->setFolio(foliomodel.get());
                                                        schoolmodel->setValueType(model::PropertyClassValueType::fromValueType(model::PropertyClassValueType::School));
                                                        if (!schoolmodel->save()) {
                                                            QString err = QString("Failed to save School Value: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                        }
                                                    }
                                                }
                                            }

                                            // Oil and Gas
                                            if (folio.OilAndGas().present()) {
                                                auto og_seq = folio.OilAndGas().get().OilAndGas();
                                                for (auto &&og : og_seq) {
                                                    auto ogmodel = model::OilAndGas::fromXml(og);
                                                    ogmodel->setFolio(foliomodel.get());
                                                    if (!ogmodel->save()) {
                                                        QString err = QString("Failed to save Oil and Gas: ") + QDjango::database().lastError().text();
                                                        throw SaveError(err);
                                                    }
                                                }
                                            }

                                            // Managed Forest
                                            if (folio.ManagedForests().present()) {
                                                auto mf_seq = folio.ManagedForests().get().ManagedForest();
                                                for (auto mf: mf_seq) {
                                                    auto mfmodel = model::ManagedForest::fromXml(mf);
                                                    mfmodel->setFolio(foliomodel.get());
                                                    if (!mfmodel->save()) {
                                                        QString err = QString("Failed to save Managed Forest: ") + QDjango::database().lastError().text();
                                                        throw SaveError(err);
                                                    }
                                                }
                                            }
                                    }
                            }
                    }
            }
        }

    catch (SaveError err) {
            QDjango::database().rollback();
            QDjango::database().close();
            emit message(QString("Error: ") +  err.text());
            emit finished();
            return;
    }
    QDjango::database().commit();
    QDjango::database().close();
    emit finished();
}

void BcaaXmlReader::processMinorTaxJurisdiction(dataadvice::MinorTaxingJurisdiction const &mtj
                                                , std::unique_ptr<model::Folio> &folio
                                                , model::minortaxing::JurisdictionType::TaxingJurisdictionType taxType)
{
    auto jurisdiction = model::minortaxing::MinorTaxingJurisdiction::fromXml(mtj);
    try {
        jurisdiction->setJurisdictionType(m_jurisdictiontypes.at(taxType).get());
    }
    catch (const std::out_of_range&) {
        throw SaveError(QString("Failed to find jurisdiction type ") + QString::number(taxType));
    }

    if (!jurisdiction->save())
    {
            QString err = QString("Failed to save ")
                    + m_jurisdictiontypes[taxType]->description()
                    + QDjango::database().lastError().text();
            throw SaveError(err);
    }
    auto minortaxing = std::make_unique<model::minortaxing::MinorTaxing>();
    minortaxing->setFolio(folio.get());
    minortaxing->setMinorTaxingJurisdiction(jurisdiction.get());
    if (!minortaxing->save())
    {
            QString err = QString("Failed to save ")
                    + m_jurisdictiontypes[taxType]->description()
                    + QDjango::database().lastError().text();
            throw SaveError(err);
    }

}
