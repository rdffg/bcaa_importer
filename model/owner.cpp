#include "ownergroup.h"
#include "owner.h"

using namespace model;
Owner::Owner(QObject *parent): QDjangoModel (parent)
{

}

QString Owner::firstname() const
{
    return m_firstname;
}

void Owner::setFirstname(const QString &firstname)
{
    m_firstname = firstname;
}

QString Owner::middleName() const
{
    return m_middleName;
}

void Owner::setMiddleName(const QString &middleName)
{
    m_middleName = middleName;
}

QString Owner::middleInitial() const
{
    return m_middleInitial;
}

void Owner::setMiddleInitial(const QString &middleInitial)
{
    m_middleInitial = middleInitial;
}

QString Owner::companyOrLastName() const
{
    return m_companyOrLastName;
}

void Owner::setCompanyOrLastName(const QString &companyOrLastName)
{
    m_companyOrLastName = companyOrLastName;
}

QString Owner::equityType() const
{
    return m_equityType;
}

void Owner::setEquityType(const QString &equityType)
{
    m_equityType = equityType;
}

QString Owner::equityTypeDescription() const
{
    return m_equityTypeDescription;
}

void Owner::setEquityTypeDescription(const QString &equityTypeDescription)
{
    m_equityTypeDescription = equityTypeDescription;
}

QString Owner::ownerSequenceID() const
{
    return m_ownerSequenceID;
}

void Owner::setOwnerSequenceID(const QString &ownerSequenceID)
{
    m_ownerSequenceID = ownerSequenceID;
}

QString Owner::id() const
{
    return m_id;
}

void Owner::setId(const QString &id)
{
    m_id = id;
}
