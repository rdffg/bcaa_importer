#include "bcaaxmlreader.h"
#include "DataAdvice.hxx"
#include <memory>
#include <QDebug>
#include <ios>
#include "QDjango.h"
#include "model/jurisdiction.h"
#include "model/folio.h"
#include "model/minortaxing/electoralarea.h"
#include "modelConverter/jurisdictionconverter.h"
#include "modelConverter/folioconverter.h"
#include "modelConverter/folioaddressconverter.h"
#include "modelConverter/assessmentareaconverter.h"
#include "modelConverter/ownershipgroupconverter.h"
#include "modelConverter/ownerconverter.h"
#include "modelConverter/mailingaddressconverter.h"
#include "modelConverter/formattedmailingaddressconverter.h"
#include "modelConverter/minortaxingjurisdictionconverter.h"
#include "saveerror.h"
#include "QSqlDatabase"


BcaaXmlReader::BcaaXmlReader(QString filePath, QObject *parent) : QObject(parent)
  , m_filePath(filePath)
{
}

void BcaaXmlReader::import() {
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

    QDjango::database().transaction();

    qDebug() << "Opened XML file...";
    emit message("Successfully opened the XML file");
    dataadvice::DataAdvice::AssessmentAreas_optional aac = da.get()->AssessmentAreas();
    if (aac.present()) {
            dataadvice::DataAdvice::AssessmentAreas_type dat = aac.get();
            try {
                    // assessment area
                    auto aa_seq = dat.AssessmentArea();
                    for (auto &&a : aa_seq) {
                            auto aamodel = std::unique_ptr<model::AssessmentArea>(converter::AssessmentAreaConverter::convert(a));
                            if (!aamodel->save()) {
                                    QString err = QString("Failed to save Assessment Area: ") + QDjango::database().lastError().text();
                                    throw SaveError(err);
                            }

                            emit message(QString("Found Assessment Area ") + QString::fromStdString(a.AssessmentAreaCode()));

                            // jurisdiction
                            auto juris_seq = a.Jurisdictions().get().Jurisdiction();
                            for (auto &&juris: juris_seq) {
                                    auto juris_model = std::unique_ptr<model::Jurisdiction>(converter::JurisdictionConverter::convert(juris));
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
                                            auto foliomodel = std::unique_ptr<model::Folio>(converter::FolioConverter::convert(folio));
                                            foliomodel->setJurisdiction(juris_model.get());
                                            if (!foliomodel->save()) {
                                                    QString err = QString("Failed to save Folio: ") + QDjango::database().lastError().text();
                                                    throw SaveError(err);

                                            }
                                            emit message(QString(" - ") + foliomodel->rollNumber());

                                            // Folio addresses
                                            if (folio.FolioAddresses().present()) {
                                                    auto addr_seq = folio.FolioAddresses().get().FolioAddress();
                                                    for (auto &&addr: addr_seq) {
                                                            auto addrmodel = converter::FolioAddressConverter::convert(addr);
                                                            addrmodel->setFolio(foliomodel.get());
                                                            if (!addrmodel->save()) {
                                                                    QString err = QString("Failed to save Folio Address: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }
                                            }

                                            // ownership groups
                                            auto own_groups_seq = folio.OwnershipGroups()->OwnershipGroup();
                                            for (auto&& og : own_groups_seq) {
                                                    auto groupmodel = std::unique_ptr<model::OwnershipGroup>(converter::OwnershipGroupConverter::convert(og));
                                                    groupmodel->setFolio(foliomodel.get());
                                                    if (!groupmodel->save()) {
                                                            QString err = QString("Failed to save OwnershipGroup: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                    }

                                                    // owners
                                                    for (auto &&owner : og.Owners().get().Owner()) {
                                                            auto ownermodel = std::unique_ptr<model::Owner>(converter::OwnerConverter::convert(owner));
                                                            ownermodel->setOwnershipGroup(groupmodel.get());
                                                            if (!ownermodel->save()) {
                                                                    QString err = QString("Failed to save Owner: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }

                                                    // mailing address
                                                    if (og.MailingAddress().present()) {
                                                            auto mamodel = std::unique_ptr<model::MailingAddress>(converter::MailingAddressConverter::convert(og.MailingAddress().get()));
                                                            mamodel->setOwnershipGroup(groupmodel.get());
                                                            if (!mamodel->save()) {
                                                                    QString err = QString("failed to save mailing address: ") + QDjango::database().lastError().text();
                                                                    throw SaveError(err);
                                                            }
                                                    }

                                                    // formatted mailing address
                                                    if (og.FormattedMailingAddress().present()) {
                                                            auto fma = converter::FormattedMailingAddressConverter::convert(og.FormattedMailingAddress().get());
                                                            fma->setOwnershipGroup(groupmodel.get());
                                                            if (!fma->save()) {
                                                                    QString err = QString("Failed to save formatted mailing address: ") + QDjango::database().lastError().text();
                                                                    throw err;
                                                            }
                                                    }
                                            }

                                            // minor taxings
                                            if (folio.MinorTaxing().present()) {
                                                    if (folio.MinorTaxing().get().GeneralServices().present()) {
                                                            auto gs = std::unique_ptr<model::minortaxing::MinorTaxingJurisdiction>(
                                                                                    converter::MinorTaxingJurisdictionConverter::convert(folio.MinorTaxing().get().GeneralServices().get()));
                                                            if (!gs->save()) {
                                                                    QString err = QString("Failed to save general services") + QDjango::database().lastError().text();
                                                                    throw err;
                                                            }

                                                            foliomodel->setGeneralService(gs.get());
                                                    }
                                                    if (folio.MinorTaxing().get().IslandsTrusts().present()) {
                                                            auto it = std::unique_ptr<model::minortaxing::MinorTaxingJurisdiction>(
                                                                                    converter::MinorTaxingJurisdictionConverter::convert(folio.MinorTaxing().get().IslandsTrusts().get()));
                                                            if (!it->save()) {
                                                                    QString err = QString("Failed to save island trust") + QDjango::database().lastError().text();
                                                                    throw err;
                                                            }
                                                            foliomodel->setIslandTrust(it.get());
                                                    }
                                                    if (!foliomodel->save()) {
                                                            QString err = QString("Failed to save minor taxings") + QDjango::database().lastError().text();
                                                            throw err;
                                                    }

                                                    // electoral areas
                                                    if (folio.MinorTaxing().get().ElectoralAreas().present()) {
                                                            auto ea_seq = folio.MinorTaxing().get().ElectoralAreas().get().MinorTaxingJurisdiction();
                                                            for (auto ea : ea_seq)
                                                            {
                                                                    auto electoralarea = new model::minortaxing::ElectoralArea();
                                                                    auto eaj = std::unique_ptr<model::minortaxing::MinorTaxingJurisdiction>(converter::MinorTaxingJurisdictionConverter::convert(ea));
                                                                    if (!eaj->save())
                                                                    {
                                                                            QString err = QString("Failed to save electoral area") + QDjango::database().lastError().text();
                                                                            throw err;
                                                                    }

                                                                    electoralarea->setMinorTaxingJurisdiction(eaj.get());
                                                                    electoralarea->setFolio(foliomodel.get());
                                                                    if (!electoralarea->save())
                                                                    {
                                                                            QString err = QString("Failed to save electoral area") + QDjango::database().lastError().text();
                                                                            throw err;
                                                                    }
                                                            }
                                                    }

                                                    // Defined

                                                    // Specified Regional

                                                    // Service Areas

                                                    // Specified Municipal

                                                    // Improvement Districts

                                                    // Local Areas
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
        }
    QDjango::database().commit();
    QDjango::database().close();
    emit finished();
}
