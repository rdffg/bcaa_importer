#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include <QUrl>
#include <QFileInfo>
#include <QSettings>
#include <QPluginLoader>
#include <QSqlDatabase>
#include <QtCore>
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "QDjangoWhere.h"
#include "bcaadataimporter.h"
#include "parser/parser.h"
#include "model/model.h"
#include "parser/DataAdvice-pimpl.h"
#include "saveerror.h"

BCAADataImporter::BCAADataImporter(QObject *parent) : QObject(parent)
  , m_datafilepath("")
  , m_isrunning(false)
  , m_totalRecords(0)
  , m_progress(0)
  , m_percentDone(-1)
  , m_canRun(false)
  , m_plugins(std::map<QString, std::unique_ptr<rdffg::IPostProcess> >())
{
    QSettings settings("rdffg", "BCAA Importer");
    QUrl dataFilePath = settings.value("history/lastFolder").toUrl();
    if (QDir(dataFilePath.toLocalFile()).exists())
        m_datafilepath = dataFilePath.toString();
    registerModels();
    m_importMeta = new model::ImportMeta(this);
}

QString BCAADataImporter::dataFilePath()
{
    return m_datafilepath;
}

void BCAADataImporter::setDataFilePath(QString path)
{
    m_datafilepath = path;
    QUrl url(path);
    QDir pth(url.toLocalFile());
    pth.cdUp();
    m_canRun = verifyDataFile();
    if (path != "") {
        QSettings settings("rdffg", "BCAA Importer");
        settings.setValue("history/lastFolder",QUrl::fromLocalFile(pth.absolutePath()));
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
#ifdef QT_DEBUG
        QDjango::setDebugEnabled(true);
#else
        QDjango::setDebugEnabled(false);
#endif
    loadPlugins();

    m_progress = 0;
    m_percentDone = -1;
    emit progressChanged();

    m_isrunning = true;
    emit runningChanged();
    if (m_dbconnection != NULL) {
        auto db = m_dbconnection->makeDbConnection();
        if(db.open()) {
            // make sqlite fast
            if (this->dbConnection()->driver() == "QSQLITE")
            {
                auto q = db.exec(QString("PRAGMA journal_mode=WAL"));
                q = db.exec("PRAGMA synchronous=OFF");
            }
            QDjango::setDatabase(db);
        } else {
            emit statusChanged(QString("Failed to open database: ") + QString(db.lastError().text()));
            qDebug() << "Failed to open database:" << db.lastError();
        }
    } else {
        qDebug() << Q_FUNC_INFO << "Database connection object was null";
        return;
    }

    QThread *t = new QThread;
    QUrl u(m_datafilepath);
    Parser *r = new  Parser(u.toLocalFile());
    QObject::connect(r, &Parser::message, [=](QString msg){
        emit this->statusChanged(msg);
    });
    r->moveToThread(t);
    QObject::connect(t, &QThread::started, r, &Parser::import);
    QObject::connect(r, &Parser::finished, [=](bool){ t->quit(); });
    QObject::connect(r, &Parser::finished, this, &BCAADataImporter::onImportFinished);
    QObject::connect(r, &Parser::folioSaved, this, &BCAADataImporter::onProgressChanged);
    QObject::connect(this, &BCAADataImporter::cancelJob, r, &Parser::cancel, Qt::DirectConnection);
    QObject::connect(t, &QThread::finished, [=] () {
        qDebug() << "parser thread finished.";
        QDjango::database().close();
        this->disconnect(r);
        r->deleteLater();
        t->deleteLater();
    });
    QObject::connect(t, &QThread::destroyed, r, &Parser::deleteLater);
    emit statusChanged(QString("Import started at " + QTime::currentTime().toString()));
    t->start();
}

void BCAADataImporter::onProgressChanged(float percent)
{
    ++m_progress;
    m_percentDone = percent;
    emit progressChanged();
}

float BCAADataImporter::percentDone()  const
{
    return m_percentDone;
}

model::ImportMeta *BCAADataImporter::importMeta() const
{
    return m_importMeta;
}

model::ImportMeta *BCAADataImporter::lastRun() const
{
    if (m_dbconnection != NULL)
    {
        auto db = m_dbconnection->makeDbConnection();
        if (db.open())
        {
            QDjango::setDatabase(db);
            QDjangoQuerySet<model::ImportMeta> qs;
            qs = qs.orderBy(QStringList("-runDate")).limit(0,1);
            if (qs.size() > 0)
                return qs.at(0);
        }
        else
        {
            emit statusChanged(QString("Failed to open database: ") + db.lastError().text());
        }
    }
    else
    {
        emit statusChanged(QString("No sql connection settings defined."));
    }
    return NULL;
}

void BCAADataImporter::onImportFinished(bool success)
{
    // run this in a thread, its own thread
    // if we have a post-processing plugin for this database type, run it
    if (success && m_plugins.find(m_dbconnection->driver()) != m_plugins.end())
    {
        m_percentDone = -1;
        emit progressChanged();
        auto t = new QThread;
        std::unique_ptr<rdffg::IPostProcess>& postPlugin = m_plugins[m_dbconnection->driver()];
        auto plugin =dynamic_cast<QObject *>(postPlugin.get());
        if (plugin != NULL)
        {
            plugin->moveToThread(t);
            connect(t, &QThread::started, [&]() {
                postPlugin->processDatabase(new QSqlDatabase(m_dbconnection->makeDbConnection()), runType());
            });
            QObject::connect(plugin, SIGNAL(finished()), t, SLOT(quit()), Qt::QueuedConnection);
            QObject::connect(t, &QThread::finished, this, [=]() {
                //t->deleteLater();
                QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
                auto actuallyDone = !t->isRunning();
            }, Qt::QueuedConnection);
            QObject::connect(this, SIGNAL(cancelJob()), plugin, SLOT(cancel()), Qt::DirectConnection);
            t->start();
            //postPlugin->processDatabase((new QSqlDatabase(m_dbconnection->makeDbConnection())), runType());
            //onRunFinished();
        }
    }
    else
    {
        emit onRunFinished();
    }
}

void BCAADataImporter::onRunFinished()
{
    emit statusChanged(QString("Import finished at ") + QTime::currentTime().toString());
    m_isrunning = false;
    m_canRun = false;
    emit dataChanged();
    emit runningChanged();
}

void BCAADataImporter::cancel()
{
    emit cancelJob();
}

void BCAADataImporter::createTables()
{
    auto db = m_dbconnection->makeDbConnection();
    if (db.open())
    {
        QDjango::setDatabase(db);
        QDjango::createTables();
    }
    else
    {
        emit statusChanged(QString("Failed to open database: ") + db.lastError().text());
    }
}

void BCAADataImporter::onStatusChanged(const QString &message)
{
    emit statusChanged(message);
}

///
/// \brief BCAADataImporter::verifyDataFile
/// \todo signal error messages back to the UI
/// \return
///
bool BCAADataImporter::verifyDataFile()
{
    try {
        auto parser = new Parser(QUrl(m_datafilepath).toLocalFile(), this);
        connect(parser, &Parser::message, this, &BCAADataImporter::statusChanged);
        auto advice = parser->getFileInfo();
        m_importMeta->setRunType(advice->runType());
        m_importMeta->setRunDate(advice->runDate());
        m_runType = advice->runType();
    } catch (const xml_schema::parsing& e)
    {
        qDebug() << e.what();
        foreach (auto d, e.diagnostics())
        {
            qDebug() << "error at " << d.line() << ", column " << d.column();
            qDebug() << QString::fromStdString(d.message());
        }
        return false;
    } catch (const xml_schema::exception& e) {
        qDebug() << e.what();
        return false;
    } catch (QString &err) {
        statusChanged(err);
        return false;
    }

    this->m_canRun = true;
    emit dataChanged();
    emit progressChanged();
    return true;
}

void BCAADataImporter::registerModels()
{
    QDjango::registerModel<model::AssessmentArea>();
    QDjango::registerModel<model::Jurisdiction>();
    QDjango::registerModel<model::Folio>();
    QDjango::registerModel<model::FolioAddress>();
    QDjango::registerModel<model::ImportMeta>();
    QDjango::registerModel<model::LandMeasurement>();
    QDjango::registerModel<model::LandCharacteristic>();
    QDjango::registerModel<model::LegalDescription>();
    QDjango::registerModel<model::ManagedForest>();
    QDjango::registerModel<model::ManualClass>();
    QDjango::registerModel<model::ManufacturedHome>();
    QDjango::registerModel<model::minortaxing::JurisdictionType>();
    QDjango::registerModel<model::minortaxing::MinorTaxingJurisdiction>();
    QDjango::registerModel<model::minortaxing::MinorTaxing>();
    QDjango::registerModel<model::OilAndGas>();
    QDjango::registerModel<model::OwnershipGroup>();
    QDjango::registerModel<model::Owner>();
    QDjango::registerModel<model::PropertyClassValueType>();
    QDjango::registerModel<model::Sale>();
    QDjango::registerModel<model::SpecialDistrict>();
    QDjango::registerModel<model::ValuesByETC>();
    QDjango::registerModel<model::Valuation>();
    QDjango::registerModel<model::PropertyClassValue>();
    QDjango::registerModel<model::Farm>();
    QDjango::registerModel<model::FolioDescription>();
    QDjango::registerModel<model::FormattedMailingAddress>();
    QDjango::registerModel<model::MailingAddress>();
    QDjango::registerModel<model::Neighbourhood>();
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

void BCAADataImporter::loadPlugins()
{
    if (!m_plugins.empty()) // already loaded
        return;

    auto pluginsDir = QDir(qApp->applicationDirPath());
    qDebug() << pluginsDir.path();
    //pluginsDir.cdUp();
    //pluginsDir.cdUp();
    //qDebug() << pluginsDir.path();
    //pluginsDir.cd("build-PostProcess-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug");
    //pluginsDir.cd("debug");
    qDebug() << pluginsDir.path();
    qDebug() << pluginsDir.isReadable();
    foreach (QString filename, pluginsDir.entryList(QDir::Files)) {
        if (filename.startsWith("Post")) {
            QPluginLoader loader(pluginsDir.absoluteFilePath(filename));
            QObject* plugin = loader.instance();
            if (plugin) {
                rdffg::IPostProcess *post = qobject_cast<rdffg::IPostProcess *>(plugin);
                QObject::connect(plugin, SIGNAL(statusChanged(QString const &)), this, SLOT(onStatusChanged(QString const &)));
                QObject::connect(plugin, SIGNAL(finished()), this, SLOT(onRunFinished()));
                m_plugins[post->databaseType()] = std::unique_ptr<rdffg::IPostProcess>(post);
                statusChanged(QString("Found post-process plugin for ") + post->databaseType());
                qDebug() << "Found Post-process plugin for " << post->databaseType();
            }
        }
    }
}

bool BCAADataImporter::canRun() const
{
    return m_canRun;
}
