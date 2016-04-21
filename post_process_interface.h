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
    virtual void processDatabase(QSqlDatabase *db, const QString &runType) = 0;
    virtual void processDatabase(const QString &runType) = 0;
    virtual void setDatabase(QSqlDatabase *db) = 0;
    virtual QString databaseType() const = 0;
signals:
    virtual void statusChanged(QString const &status) = 0;
    virtual void finished() = 0;
private:
    QSqlDatabase *m_database;
};
}

Q_DECLARE_INTERFACE(rdffg::IPostProcess, "rdffg.bc.ca.IPostProcess")
#endif // POST_PROCESS_INTERFACE_H
