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

BCAADataImporter::BCAADataImporter(QObject *parent) : QObject(parent)
  , m_datafilepath("")
  , m_isrunning(false)
{
    QSettings settings("rdffg", "BCAA Importer");
    m_datafilepath = settings.value("history/lastFolder").toString();
    QDjango::registerModel<Jurisdiction>();
    QDjango::registerModel<Folio>();
}

QString BCAADataImporter::dataFilePath()
{
    return m_datafilepath;
}

void BCAADataImporter::setDataFilePath(QString path)
{
    m_datafilepath = path;
    QSettings settings("rdffg", "BCAA Importer");
    settings.setValue("history/lastFolder", m_datafilepath);
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
    QObject::connect(r, &BcaaXmlReader::finished, r, &BcaaXmlReader::deleteLater);
    t->start();


    m_isrunning = false;
    emit runningChanged();
}

void BCAADataImporter::testDb() {
    Jurisdiction *j = new Jurisdiction();
    j->setCode("200");
    j->setDescription("Vancouver");
    qDebug() << "Jurisiction save: " << j->save();

    Folio *f = new Folio();
    f->setJurisdiction(j);
    f->setRollNumber("00000000");
    f->setStatus("01");
    f->setStatusDescription("Active");
    qDebug() << "Folio save: " << f->save();
    QDjango::database().close();
}

