#ifndef BCAADATAIMPORTER_H
#define BCAADATAIMPORTER_H
#include <QObject>
#include "dbconnectionsettings.h"

class BCAADataImporter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dataFilePath READ dataFilePath WRITE setDataFilePath NOTIFY dataChanged)
    Q_PROPERTY(bool isRunning READ isRunning NOTIFY runningChanged)
public:
    explicit BCAADataImporter(QObject *parent = 0);
    QString dataFilePath();
    void setDataFilePath(QString path);
    DbConnectionSettings *dbConnection();
    void setDbConnection(DbConnectionSettings *db);
    bool isRunning();

signals:
    void statusChanged(QString message);
    void runningChanged();
    void dataChanged();

public slots:
    Q_INVOKABLE void beginImport();

private:
    void registerModels();
    DbConnectionSettings *m_dbconnection;
    QString m_datafilepath;
    bool m_isrunning;
};

#endif // BCAADATAIMPORTER_H
