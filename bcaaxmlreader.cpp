#include "bcaaxmlreader.h"
#include "DataAdvice.hxx"
#include <memory>
#include <QDebug>
#include <ios>
#include "QDjango.h"
#include "model/jurisdiction.h"
#include "model/folio.h"
#include "modelConverter/jurisdictionconverter.h"
#include "modelConverter/folioconverter.h"
#include "modelConverter/folioaddressconverter.h"
#include "modelConverter/assessmentareaconverter.h"
#include "modelConverter/ownershipgroupconverter.h"
#include "modelConverter/ownerconverter.h"
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
    QDjango::dropTables();
    QDjango::createTables();

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
                    auto aamodel = converter::AssessmentAreaConverter::convert(a);
                    if (!aamodel.get()->save()) {
                            QString err = QString("Failed to save Assessment Area: ") + QDjango::database().lastError().text();
                            throw SaveError(err);
                    }

                    emit message(QString("Found Assessment Area ") + QString::fromStdString(a.AssessmentAreaCode()));

                    // jurisdiction
                    auto juris_seq = a.Jurisdictions().get().Jurisdiction();
                    for (auto &&juris: juris_seq) {
                            Jurisdiction *juris_model = converter::JurisdictionConverter::convert(juris);
                            emit message(QString("Found Jurisdiction ")
                                         + juris_model->description());
                            juris_model->setAssessmentArea(aamodel);
                            if (!juris_model->save()) {
                                    QString err = QString("Failed to save Jurisdiction: ") + QDjango::database().lastError().text();
                                    throw SaveError(err);

                            }

                            // folio
                            auto folio_seq = juris.FolioRecords().get().FolioRecord();
                            for (auto &&folio : folio_seq) {
                                    Folio *foliomodel = converter::FolioConverter::convert(folio);
                                    foliomodel->setJurisdiction(juris_model);
                                    if (!foliomodel->save()) {
                                            QString err = QString("Failed to save Folio: ") + QDjango::database().lastError().text();
                                            throw SaveError(err);

                                    }
                                    emit message(QString(" - ") + foliomodel->rollNumber());

                                    // Folio addresses
                                    if (folio.FolioAddresses().present()) {
                                            auto addr_seq = folio.FolioAddresses().get().FolioAddress();
                                            for (auto &&addr: addr_seq) {
                                                    FolioAddress *addrmodel = converter::FolioAddressConverter::convert(addr);
                                                    addrmodel->setFolio(foliomodel);
                                                    if (!addrmodel->save()) {
                                                            QString err = QString("Failed to save Folio Address: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                    }
                                                    delete addrmodel;
                                            }
                                    }

                                    // ownership groups
                                    auto own_groups_seq = folio.OwnershipGroups()->OwnershipGroup();
                                    for (auto&& og : own_groups_seq) {
                                            auto groupmodel = converter::OwnershipGroupConverter::convert(og);
                                            groupmodel->setFolio(foliomodel);
                                            if (!groupmodel->save()) {
                                                    QString err = QString("Failed to save OwnershipGroup: ") + QDjango::database().lastError().text();
                                                    throw SaveError(err);
                                            }

                                            // owners
                                            for (auto &&owner : og.Owners().get().Owner()) {
                                                    auto ownermodel = std::unique_ptr<Owner>(converter::OwnerConverter::convert(owner));
                                                    if (!ownermodel->save()) {
                                                            QString err = QString("Failed to save Owner: ") + QDjango::database().lastError().text();
                                                            throw SaveError(err);
                                                    }
                                            }

                                            delete groupmodel;
                                    }

                                    delete foliomodel;
                            }
                            delete juris_model;
                    }
                }
            } catch (SaveError err) {
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
