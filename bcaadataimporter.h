#ifndef BCAADATAIMPORTER_H
#define BCAADATAIMPORTER_H
#include <QObject>
#include <map>
#include "post_process_interface.h"
#include "dbconnectionsettings.h"

class BCAADataImporter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dataFilePath READ dataFilePath WRITE setDataFilePath NOTIFY dataChanged)
    Q_PROPERTY(bool isRunning READ isRunning NOTIFY runningChanged)
    Q_PROPERTY(long long totalRecords READ totalRecords NOTIFY progressChanged)
    Q_PROPERTY(long long progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(float percentDone READ percentDone NOTIFY progressChanged)
    Q_PROPERTY(QString runType READ runType WRITE setRunType NOTIFY dataChanged)
    Q_PROPERTY(bool canRun READ canRun NOTIFY dataChanged)

public:
    explicit BCAADataImporter(QObject *parent = 0);
    QString dataFilePath();
    void setDataFilePath(QString path);
    DbConnectionSettings *dbConnection();
    void setDbConnection(DbConnectionSettings *db);
    bool isRunning();
    Q_INVOKABLE bool verifyDataFile();
    long long totalRecords() const;
    long long progress()  const;
    float percentDone() const;

    QString runType() const;
    void setRunType(const QString &runType);
    bool canRun() const;

signals:
    void statusChanged(QString const &message);
    void runningChanged();
    void dataChanged();
    void progressChanged();
    void cancelJob();

public slots:
    Q_INVOKABLE void beginImport();
    Q_INVOKABLE void cancel();

private slots:
    void onStatusChanged(QString const &message);
    void onProgressChanged(float percent);
    void onImportFinished(bool success);

private:
    void registerModels();
    void loadPlugins();
    DbConnectionSettings *m_dbconnection;
    QString m_datafilepath;
    bool m_isrunning;
    long long m_totalRecords;
    long long m_progress;
    float m_percentDone;
    QString m_runType;
    bool m_canRun;
    std::map<QString, std::unique_ptr<rdffg::IPostProcess> > m_plugins;
};

#endif // BCAADATAIMPORTER_H
