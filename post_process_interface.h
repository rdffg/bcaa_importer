#ifndef POST_PROCESS_INTERFACE_H
#define POST_PROCESS_INTERFACE_H
#include <QtCore>

namespace rdffg {
class IPostProcess {
public:
    virtual ~IPostProcess() {}
    virtual void processDatabase(const QString &runType) = 0;
    virtual QString databaseType() const = 0;
signals:
    virtual void statusChanged(QString status) = 0;
    virtual void finished() = 0;
};
}

Q_DECLARE_INTERFACE(rdffg::IPostProcess, "rdffg.bc.ca.IPostProcess")
#endif // POST_PROCESS_INTERFACE_H

