#include <QtGlobal>
#include <QStringBuilder>
#include <QDebug>
#include <QSqlError>
#include <QSettings>
#include "dbconnectionsettings.h"

DbConnectionSettings::DbConnectionSettings(QObject *parent) : QObject(parent)
  , m_driver("")
  , m_server("")
  , m_database("")
  , m_username("")
  , m_password("")
{
    loadSettings();
    emit dataChanged();
}

QStringList DbConnectionSettings::drivers() {
    auto drivers = QSqlDatabase::drivers();
    drivers.push_front("MSSQL");
    return drivers;
}

QString DbConnectionSettings::driver()
{
    return m_driver;
}

void DbConnectionSettings::setDriver(QString driver)
{
    m_driver = driver;
    emit dataChanged();
}

QString DbConnectionSettings::server() {
    return m_server;
}

void DbConnectionSettings::setServer(QString server) {
    m_server = server;
    emit dataChanged();
}

QString DbConnectionSettings::database() {
    return m_database;
}

void DbConnectionSettings::setDatabase(QString db) {
    m_database = db;
    emit dataChanged();
}

QString DbConnectionSettings::username() {
   return m_username;
}

void DbConnectionSettings::setUsername(QString username) {
    m_username = username;
    emit dataChanged();
}

QString DbConnectionSettings::password() {
    return m_password;
}

void DbConnectionSettings::setPassword(QString password) {
    m_password = password;
    emit dataChanged();
}

bool DbConnectionSettings::tryDbConnection() {
    auto db = this->makeDbConnection();
    if (!db.open()) {
        qDebug() << Q_FUNC_INFO << db.lastError();
        return false;
    } else {
        return true;
    }
}

QSqlDatabase DbConnectionSettings::makeDbConnection()
{
    QSqlDatabase db;
    if (this->driver() == "MSSQL") {
        db = QSqlDatabase::addDatabase("QODBC");
    }
    else {
        db = QSqlDatabase::addDatabase(this->driver());
    }
    if (this->driver() == "QSQLITE" && this->database() == "") {
        db.setDatabaseName(":memory:");
    } else if (this->driver() == "MSSQL") {
        db.setDatabaseName(makeMssqlConnString());
    } else {
        db.setDatabaseName(this->database());
    }
    return db;
}

QString DbConnectionSettings::makeMssqlConnString() {
    QString connstr = "Driver={SQL Server Native Client 11.0};Server="
            % this->server()
            % ";Database="
            % this->database();
    if (this->username().isEmpty() || this->username().isNull()) {
        connstr += ";Trusted_connection=yes;";
    }
    return connstr;
}

void DbConnectionSettings::saveSettings() {
    QSettings settings("rdffg", "BCAA Importer");
    settings.setValue("dbconnection/driver", m_driver);
    settings.setValue("dbconnection/server", m_server);
    settings.setValue("dbconnection/database", m_database);
    settings.setValue("dbconnection/username", m_username);
    settings.setValue("dbconnection/password", m_password);
}

void DbConnectionSettings::loadSettings() {
    QSettings settings("rdffg", "BCAA Importer");
    m_driver = settings.value("dbconnection/driver").toString();
    m_server = settings.value("dbconnection/server").toString();
    m_database = settings.value("dbconnection/database").toString();
    m_username = settings.value("dbconnection/username").toString();
    m_password = settings.value("dbconnection/password").toString();
}
