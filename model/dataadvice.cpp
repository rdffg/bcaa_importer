#include "dataadvice.h"

namespace model {

using namespace model;
DataAdvice::DataAdvice():
    m_rollYear(0)
  , m_ownershipYear(0)
  , m_runType("")
  , m_startdate(QDate())
  , m_endDate(QDate())
  , m_version("")
  , m_requestID("")
  , m_orderID("")
  , m_runDate(QDate())
{

}

long long DataAdvice::rollYear() const
{
    return m_rollYear;
}

void DataAdvice::setRollYear(long long rollYear)
{
    m_rollYear = rollYear;
}

long long DataAdvice::ownershipYear() const
{
    return m_ownershipYear;
}

void DataAdvice::setOwnershipYear(long long ownershipYear)
{
    m_ownershipYear = ownershipYear;
}

QString DataAdvice::runType() const
{
    return m_runType;
}

void DataAdvice::setRunType(const QString &runType)
{
    m_runType = runType;
}

QDate DataAdvice::startdate() const
{
    return m_startdate;
}

void DataAdvice::setStartdate(const QDate &startdate)
{
    m_startdate = startdate;
}

QDate DataAdvice::endDate() const
{
    return m_endDate;
}

void DataAdvice::setEndDate(const QDate &endDate)
{
    m_endDate = endDate;
}

const std::unique_ptr<DeliverySummary> &DataAdvice::reportSummary()
{
    return m_reportSummary;
}

void DataAdvice::setReportSummary(std::unique_ptr<DeliverySummary> reportSummary)
{
    m_reportSummary = std::move(reportSummary);
}

QString DataAdvice::version() const
{
    return m_version;
}

void DataAdvice::setVersion(const QString &version)
{
    m_version = version;
}

QString DataAdvice::requestID() const
{
    return m_requestID;
}

void DataAdvice::setRequestID(const QString &requestId)
{
    m_requestID = requestId;
}

QString DataAdvice::orderID() const
{
    return m_orderID;
}

void DataAdvice::setOrderID(const QString &orderID)
{
    m_orderID = orderID;
}

QDate DataAdvice::runDate() const
{
    return m_runDate;
}

void DataAdvice::setRunDate(const QDate &runDate)
{
    m_runDate = runDate;
}

} // namespace model
