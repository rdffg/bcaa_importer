#ifndef POST_PROCESS_INTERFACE_H
#define POST_PROCESS_INTERFACE_H
#include <QtCore>
#include <QSqlDatabase>

namespace rdffg {
/**
 * @brief The IPostProcess interface
 */
class IPostProcess {
public:
    virtual ~IPostProcess() {}
    /**
     * @brief processDatabase Post processes the given database
     * according to the given run type (yearly, monthly, revised, etc).
     * @param db
     * @param runType
     */
    virtual void processDatabase(QSqlDatabase *db, const QString &runType) = 0;
    /**
     * @brief processDatabase Post processes the database according
     * to the given run type (yearly, monthly, revised, etc).
     * @param runType
     */
    virtual void processDatabase(const QString &runType) = 0;
    virtual void setDatabase(QSqlDatabase *db) = 0;
    /** \summary Returns the database driver name. This should be
     * name of the QSql driver (QODBC, QSQLITE, QPGQL, QMYSQL, etc),
     * or MSSQL, which is handled as a special case of QODBC.
     */
    virtual QString databaseType() const = 0;
signals:
    /**
     * @brief statusChanged - Generic status messages
     * @param status
     */
    virtual void statusChanged(QString const &status) = 0;
    /**
     * @brief finished
     */
    virtual void finished() = 0;
private:
    QSqlDatabase *m_database;
};
}

Q_DECLARE_INTERFACE(rdffg::IPostProcess, "rdffg.bc.ca.IPostProcess")
#endif // POST_PROCESS_INTERFACE_H
