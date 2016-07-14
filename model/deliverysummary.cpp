#include "deliverysummary.h"

using namespace model;

DeliverySummary::DeliverySummary() : m_totalFolioCount(0)
{

}

long long DeliverySummary::totalFolioCount() const
{
    return m_totalFolioCount;
}

void DeliverySummary::setTotalFolioCount(long long totalFolioCount)
{
    m_totalFolioCount = totalFolioCount;
}
