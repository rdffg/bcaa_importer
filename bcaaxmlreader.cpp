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
    QDjango::createTables();

    qDebug() << "Opened XML file...";
    emit message("Successfully opened the XML file");
    dataadvice::DataAdvice::AssessmentAreas_optional aac = da.get()->AssessmentAreas();
    if (aac.present()) {
            dataadvice::DataAdvice::AssessmentAreas_type dat = aac.get();
            auto aa_seq = dat.AssessmentArea();
            for (auto i (aa_seq.begin()); i != aa_seq.end(); ++i) {
                dataadvice::AssessmentArea& a (*i);
                emit message(QString("Found Assessment Area ") + QString::fromStdString(a.AssessmentAreaCode()));
                auto juris_seq = a.Jurisdictions().get().Jurisdiction();
                for (auto j (juris_seq.begin()); j != juris_seq.end(); ++j) {
                    dataadvice::Jurisdiction &juris (*j);
                    Jurisdiction *juris_model = converter::JurisdictionConverter::convert(juris);
                    emit message(QString("Found Jurisdiction ")
                                 + juris_model->description());
                    juris_model->save();
                    auto folio_seq = juris.FolioRecords().get().FolioRecord();
                    for (auto f (folio_seq.begin()); f != folio_seq.end(); f++) {
                        dataadvice::FolioRecord &folio (*f);
                        Folio *foliomodel = converter::FolioConverter::convert(folio);
                        foliomodel->setJurisdiction(juris_model);
                        foliomodel->save();
                        emit message(QString(" - ") + foliomodel->rollNumber());
                        delete foliomodel;
                    }
                    delete juris_model;
                }
            }
        }
    QDjango::database().commit();
    QDjango::database().close();
    emit finished();
}
