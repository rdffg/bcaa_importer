#ifndef DBCONNECTIONSETTINGS_H
#define DBCONNECTIONSETTINGS_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QStringList>
#include <memory>

class DbConnectionSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList drivers READ drivers NOTIFY dataChanged)
    Q_PROPERTY(QString driver READ driver WRITE setDriver NOTIFY dataChanged)
    Q_PROPERTY(QString server READ server WRITE setServer NOTIFY dataChanged)
    Q_PROPERTY(QString database READ database WRITE setDatabase NOTIFY dataChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY dataChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY dataChanged)

public:
    explicit DbConnectionSettings(QObject *parent = 0);
    /**
     * @brief drivers - get a list of available database drivers
     *
     * @return QStringList
     */
    QStringList drivers();
    /**
     * @brief driver - get name of the current database driver
     * @return
     */
    QString driver();
    /**
     * @brief setDriver - set the current database driver
     * @param driver
     */
    void setDriver(QString driver);
    /**
     * @brief server - get the name of the database server
     * @return
     */
    QString server();
    /**
     * @brief setServer - set the name of the database server
     * @param server
     */
    void setServer(QString server);
    /**
     * @brief database - get the name of the database
     * @return
     */
    QString database();
    /**
     * @brief setDatabase - set the name of the database
     * @param db
     */
    void setDatabase(QString db);
    /**
     * @brief username - get the username
     * @return QString
     */
    QString username();
    /**
     * @brief setUsername set the username
     * @param username
     */
    void setUsername(QString username);
    /**
     * @brief password - get the password
     * @details This should probably not exist, or maybe
     *      should return a
     * @return
     */
    QString password();
    /**
     * @brief setPassword - set the password
     * @param password
     */
    void setPassword(QString password);
    /**
     * @brief tryDbConnection - test the database connection
     * @return
     */
    Q_INVOKABLE bool tryDbConnection();
    /**
     *  @brief Save settings to disk
    **/
    Q_INVOKABLE void saveSettings();
    /**
     *  @brief Load settings from disk
    **/
    Q_INVOKABLE void loadSettings();
    /**
     * @brief makeDbConnection - create a DB connection
     * @details Create a database connection object from the entered
     *      parameters. The connection object return is configured,
     *      but not opened.
     * @return std::unique_ptr<QSqlDatabase>
     */
    QSqlDatabase makeDbConnection();

signals:
    void dataChanged();
public slots:

private:
    QString m_driver;
    QString m_server;
    QString m_database;
    QString m_username;
    QString m_password;
    QString makeMssqlConnString();
};

#endif // DBCONNECTIONSETTINGS_H
