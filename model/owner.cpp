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

OwnershipGroup *Owner::ownershipGroup() const {
    return qobject_cast<OwnershipGroup *>(foreignKey(OWNERSHIPGROUP_PROPERTY));
}

void Owner::setOwnershipGroup(OwnershipGroup *ownershipGroup) {
    setForeignKey(OWNERSHIPGROUP_PROPERTY, ownershipGroup);
}

model::Owner *Owner::fromXml(const dataadvice::Owner &xowner) {
    auto owner = new model::Owner();
    owner->setCompanyOrLastName(QString::fromStdString(xowner.CompanyOrLastName()));
    if (xowner.FirstName().present())
        owner->setFirstname(QString::fromStdString(xowner.FirstName().get()));
    if (xowner.MiddleInitial().present())
        owner->setMiddleInitial(QString::fromStdString(xowner.MiddleInitial().get()));
    if (xowner.MiddleName().present())
        owner->setMiddleName(QString::fromStdString(xowner.MiddleName().get()));
    if (xowner.EquityType().present())
        owner->setEquityType(QString::fromStdString(xowner.EquityType().get()));
    if (xowner.EquityTypeDescription().present())
        owner->setEquityTypeDescription(QString::fromStdString(xowner.EquityTypeDescription().get()));
    return owner;
}
