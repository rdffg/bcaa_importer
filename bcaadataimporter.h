/**
 *
 *
 */

#ifndef BCAADATAIMPORTER_H
#define BCAADATAIMPORTER_H
#include <QObject>
#include <map>
#include "post_process_interface.h"
#include "dbconnectionsettings.h"
#include "model/importmeta.h"

/**
 * @brief The BCAADataImporter class
 *
 * This is the class that drives the import job, and provides data to the UI
 *
 * @note This class is convoluted, and should be refactored into a bunch of smaller
 * classes.
 */
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
    Q_PROPERTY(model::ImportMeta *lastRun READ lastRun NOTIFY dataChanged)
    Q_PROPERTY(model::ImportMeta *importMeta READ importMeta NOTIFY dataChanged)
    Q_PROPERTY(QStringList plugins READ plugins NOTIFY pluginsChanged)

public:
    explicit BCAADataImporter(QObject *parent = 0);
    /**
     * @brief returns the filesystem path of the currently selected data file
     * @return
     */
    QString dataFilePath();
    /**
     * @brief Set the path for the current data file
     *
     * The QString given by the path parameter will be checked for validity.
     * If the parameter is a valid file, the canRun() function will return true.
     * The directory part of the path will be saved in the application settings.
     * @param path
     */
    void setDataFilePath(QString path);
    /**
     * @brief dbConnection returns a DbConnectionSettings object with the current
     * database connection settings.
     * @return
     */
    DbConnectionSettings *dbConnection();
    /**
     * @brief Set the DbConnectionSettings object.
     * @param db
     */
    void setDbConnection(DbConnectionSettings *db);
    /**
     * @brief Returns true if there is an import job running.
     * @return
     */
    bool isRunning();
    /**
     * @brief Returns true if the current path returned by dataFilePath() points to
     * a valid file.
     *
     */
    Q_INVOKABLE bool verifyDataFile();
    /**
     * @brief Returns the total number of records in the currently selected data file.
     * @return
     */
    long long totalRecords() const;
    /**
     * @brief returns the number of records processed in the current job.
     * @return
     */
    long long progress()  const;
    /**
     * @brief Returns the percentage of the file read.
     * @return
     */
    float percentDone() const;
    /**
     * @brief Returns the run type (monthly, yearly, supplemental, etc).
     * @return
     */
    QString runType() const;
    /**
     * @brief The date that the input file is current for.
     * @return
     */
    QDate runDate() const;
    /**
     * @brief Returns metadata for the currently selected file.
     * @return
     */
    model::ImportMeta *importMeta() const;
    /**
     * @brief Returns the metadata for the last imported data file.
     * @return
     */
    model::ImportMeta *lastRun() const;
    /**
     * @brief Set the current run type;
     * @param runType
     */
    void setRunType(const QString &runType);
    /**
     * @brief Returns true if the prerequisites to run a job are met.
     * @return
     */
    bool canRun() const;

    /**
     * @brief Returns a list of loaded post-process plugins
     */
    QStringList plugins() const;

signals:
    /**
     * @brief Job status has changed
     * @param message
     */
    void statusChanged(QString const &message) const;
    /**
     * @brief isRunning() has changed
     */
    void runningChanged();
    /**
     * @brief One or more data fields have changed
     */
    void dataChanged() const;
    /**
     * @brief The progress field has been updated
     */
    void progressChanged();
    /**
     * @brief Requests that the currently running job be canceled.
     */
    void cancelJob();
    /**
      * @brief The list of loaded plugins changed
      */
    void pluginsChanged() const;

public slots:
    /**
      * @brief Start the import job
      */
    Q_INVOKABLE void beginImport();
    /**
      * @brief cancel the current import job
      */
    Q_INVOKABLE void cancel();

    Q_INVOKABLE void createTables();

private slots:
    void onStatusChanged(QString const &message);
    void onProgressChanged(float percent);
    void onImportFinished(bool success);
    void onRunFinished();

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
    model::ImportMeta *m_importMeta;
    std::map<QString, std::unique_ptr<rdffg::IPostProcess> > m_plugins;
    bool removeOrphanOwners();
};

#endif // BCAADATAIMPORTER_H
