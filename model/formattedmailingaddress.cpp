#include "formattedmailingaddress.h"

using namespace model;
FormattedMailingAddress::FormattedMailingAddress(QObject *parent) : QDjangoModel(parent)
{

}

QString FormattedMailingAddress::line1() const
{
    return m_line1;
}

void FormattedMailingAddress::setLine1(const QString &line1)
{
    m_line1 = line1;
}

QString FormattedMailingAddress::line2() const
{
    return m_line2;
}

void FormattedMailingAddress::setLine2(const QString &line2)
{
    m_line2 = line2;
}

QString FormattedMailingAddress::line3() const
{
    return m_line3;
}

void FormattedMailingAddress::setLine3(const QString &line3)
{
    m_line3 = line3;
}

QString FormattedMailingAddress::line4() const
{
    return m_line4;
}

void FormattedMailingAddress::setLine4(const QString &line4)
{
    m_line4 = line4;
}

QString FormattedMailingAddress::line5() const
{
    return m_line5;
}

void FormattedMailingAddress::setLine5(const QString &line5)
{
    m_line5 = line5;
}

QString FormattedMailingAddress::line6() const
{
    return m_line6;
}

void FormattedMailingAddress::setLine6(const QString &line6)
{
    m_line6 = line6;
}

OwnershipGroup* FormattedMailingAddress::ownershipGroup() const
{
    return qobject_cast<OwnershipGroup*>(foreignKey(OWNERSHIPGROUP_PROPERTY));
}

void FormattedMailingAddress::setOwnershipGroup(OwnershipGroup *group) {
    setForeignKey(OWNERSHIPGROUP_PROPERTY, group);
}
