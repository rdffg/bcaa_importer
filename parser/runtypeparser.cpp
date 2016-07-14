#include "runtypeparser.h"
#include "DataAdvice-pimpl.h"

namespace dataadvice
{
RunTypeParser::RunTypeParser(): QObject(0) {}

void RunTypeParser::pre()
{
    m_dataAdvice = std::make_unique<model::DataAdvice>();
}

void RunTypeParser::RollYear(long long rollYear)
{
    m_dataAdvice->setRollYear(rollYear);
}

void RunTypeParser::OwnershipYear(long long ownershipYear)
{
    m_dataAdvice->setOwnershipYear(ownershipYear);
}

void RunTypeParser::RunType(const QString &runType)
{
    m_dataAdvice->setRunType(runType);
}

void RunTypeParser::StartDate(const xml_schema::date &date)
{
    m_dataAdvice->setStartdate(QDate(date.year(), date.month(), date.day()));
}

void RunTypeParser::EndDate(const xml_schema::date &date)
{
    m_dataAdvice->setEndDate(QDate(date.year(), date.month(), date.day()));
    // done parsing the actual DataAdvice element
    // stop parsing to avoid having to run through the whole file
    throw StopParsing();
}

void RunTypeParser::Version(const QString &version)
{
    m_dataAdvice->setVersion(version);
}

void RunTypeParser::RequestID(const QString &requestID)
{
    m_dataAdvice->setRequestID(requestID);
}

void RunTypeParser::OrderID(const QString &orderID)
{
    m_dataAdvice->setOrderID(orderID);
}

void RunTypeParser::RunDate(const xml_schema::date &date)
{
    m_dataAdvice->setRunDate(QDate(date.year(), date.month(), date.day()));
}

std::unique_ptr<model::DataAdvice> RunTypeParser::post_DataAdvice()
{
    return std::move(m_dataAdvice);
}
}
