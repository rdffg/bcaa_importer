#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include <QUrl>
#include <QFileInfo>
#include <QSettings>
#include "QDjango.h"
#include "bcaadataimporter.h"
#include "bcaaxmlreader.h"
#include "model/folio.h"
#include "model/jurisdiction.h"
#include "model/folioaddress.h"
#include "model/assessmentarea.h"
#include "model/ownergroup.h"
#include "model/owner.h"
#include "model/mailingaddress.h"
#include "model/formattedmailingaddress.h"
#include "model/minortaxing/minortaxingjurisdiction.h"
#include "model/minortaxing/minortaxing.h"
#include "model/minortaxing/electoralarea.h"
#include "model/minortaxing/servicearea.h"
#include "model/minortaxing/specifiedregional.h"
#include "model/minortaxing/defined.h"
#include "model/importmeta.h"
#include "bcaafilereader.h"
#include "DataAdvice.hxx"

BCAADataImporter::BCAADataImporter(QObject *parent) : QObject(parent)
  , m_datafilepath("")
  , m_isrunning(false)
{
    QSettings settings("rdffg", "BCAA Importer");
    m_datafilepath = settings.value("history/lastFolder").toString();
    registerModels();
}

QString BCAADataImporter::dataFilePath()
{
    return m_datafilepath;
}

void BCAADataImporter::setDataFilePath(QString path)
{
    m_datafilepath = path;
    if (path != "") {
        QSettings settings("rdffg", "BCAA Importer");
        settings.setValue("history/lastFolder", m_datafilepath);
    }
}

DbConnectionSettings *BCAADataImporter::dbConnection() {
    return m_dbconnection;
}

void BCAADataImporter::setDbConnection(DbConnectionSettings *db) {
    m_dbconnection = db;
}

bool BCAADataImporter::isRunning() {
    return m_isrunning;
}

void BCAADataImporter::beginImport()
{
    QDjango::setDebugEnabled(true);
    m_progress = 0;
    emit progressChanged();

    m_isrunning = true;
    emit runningChanged();
    if (m_dbconnection != NULL) {
        auto db = m_dbconnection->makeDbConnection();
        if(db.open()) {
            QDjango::setDatabase(db);
            QDjango::createTables();
        } else {
            qDebug() << "Failed to open database:" << db.lastError();
        }
    } else {
        qDebug() << Q_FUNC_INFO << "Database connection object was null";
        return;
    }

    QThread *t = new QThread;
    QUrl u(m_datafilepath);
    BcaaXmlReader *r = new  BcaaXmlReader(u.toLocalFile());
    QObject::connect(r, &BcaaXmlReader::message, [=](QString msg){
        emit this->statusChanged(msg);
    });
    r->moveToThread(t);
    QObject::connect(t, &QThread::started, r, &BcaaXmlReader::import);
    QObject::connect(r, &BcaaXmlReader::finished, t, &QThread::quit);
    QObject::connect(t, &QThread::finished, t, &QThread::deleteLater);
    QObject::connect(r, &BcaaXmlReader::finished, [=]() { m_isrunning = false; emit runningChanged(); });
    QObject::connect(r, &BcaaXmlReader::finished, r, &BcaaXmlReader::deleteLater);
    QObject::connect(r, &BcaaXmlReader::folioSaved, [=]() { m_progress += 1; emit progressChanged(); QApplication::processEvents(); });
    QObject::connect(this, &BCAADataImporter::cancelJob, [=]() { r->continueJob = false; });
    t->start();
}

void BCAADataImporter::cancel()
{
    emit cancelJob();
}

bool BCAADataImporter::verifyDataFile()
{
    try {
        auto advice = BCAAFileReader::openFile(m_datafilepath);
        setRunType(QString::fromStdString(advice->RunType()));
        if (advice->ReportSummary()->TotalFolioCount().present())
                m_totalRecords = advice->ReportSummary()->TotalFolioCount().get();
    } catch (const xml_schema::exception& e) {
        qDebug() << e.what();
        return false;
    }
    emit dataChanged();
    return true;
}

void BCAADataImporter::registerModels()
{
    QDjango::registerModel<model::AssessmentArea>();
    QDjango::registerModel<model::FolioAddress>();
    QDjango::registerModel<model::Jurisdiction>();
    QDjango::registerModel<model::Folio>();
    QDjango::registerModel<model::OwnershipGroup>();
    QDjango::registerModel<model::Owner>();
    QDjango::registerModel<model::MailingAddress>();
    QDjango::registerModel<model::FormattedMailingAddress>();
    QDjango::registerModel<model::minortaxing::MinorTaxingJurisdiction>();
    QDjango::registerModel<model::minortaxing::ElectoralArea>();
    QDjango::registerModel<model::minortaxing::ServiceArea>();
    QDjango::registerModel<model::minortaxing::SpecifiedRegional>();
    QDjango::registerModel<model::minortaxing::Defined>();
    QDjango::registerModel<model::ImportMeta>();
}

QString BCAADataImporter::runType() const
{
    return m_runType;
}

void BCAADataImporter::setRunType(const QString &runType)
{
    m_runType = runType;
    emit dataChanged();
}

long long BCAADataImporter::totalRecords() const
{
    return m_totalRecords;
}

long long BCAADataImporter::progress() const
{
    return m_progress;
}
