#ifndef MODEL_DATAADVICE_H
#define MODEL_DATAADVICE_H
#include <QDate>
#include <memory>
#include "model/deliverysummary.h"

namespace model
{
class DataAdvice
{
public:
    DataAdvice();
    long long rollYear() const;
    void setRollYear(long long rollYear);

    long long ownershipYear() const;
    void setOwnershipYear(long long ownershipYear);

    QString runType() const;
    void setRunType(const QString &runType);

    QDate startdate() const;
    void setStartdate(const QDate &startdate);

    QDate endDate() const;
    void setEndDate(const QDate &endDate);

    std::unique_ptr<DeliverySummary>& reportSummary();
    void setReportSummary(std::unique_ptr<DeliverySummary> &reportSummary );

    QString version() const;
    void setVersion(const QString &version);

    QString requestID() const;
    void setRequestID(const QString &requestID);

    QString orderID() const;
    void setOrderID(const QString &orderID);

    QDate runDate() const;
    void setRunDate(const QDate &runDate);

    DataAdvice(DataAdvice&da);

private:
    long long m_rollYear;
    long long m_ownershipYear;
    QString m_runType;
    QDate m_startdate;
    QDate m_endDate;
    std::unique_ptr<model::DeliverySummary> m_reportSummary;
    QString m_version;
    QString m_requestID;
    QString m_orderID;
    QDate m_runDate;
};
}
#endif // DELIVERYSUMMARY_H
