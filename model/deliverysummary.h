#ifndef DELIVERYSUMMARY_H
#define DELIVERYSUMMARY_H
#include <QDate>

namespace model
{
class DeliverySummary
{
public:
    DeliverySummary();
    long long totalFolioCount() const;
    void setTotalFolioCount(long long totalFolioCount);

private:
    long long m_totalFolioCount;
};
}
#endif // DELIVERYSUMMARY_H
