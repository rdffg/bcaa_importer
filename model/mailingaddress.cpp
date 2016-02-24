#include "mailingaddress.h"

using namespace model;
MailingAddress::MailingAddress(QObject *parent) : QDjangoModel(parent)
{

}

QString MailingAddress::attention() const
{
    return m_attention;
}

void MailingAddress::setAttention(const QString &attention)
{
    m_attention = attention;
}

QString MailingAddress::careOf() const
{
    return m_careOf;
}

void MailingAddress::setCareOf(const QString &careOf)
{
    m_careOf = careOf;
}

QString MailingAddress::floor() const
{
    return m_floor;
}

void MailingAddress::setFloor(const QString &floor)
{
    m_floor = floor;
}

QString MailingAddress::unitNumber() const
{
    return m_unitNumber;
}

void MailingAddress::setUnitNumber(const QString &unitNumber)
{
    m_unitNumber = unitNumber;
}

QString MailingAddress::streetDirectionPrefix() const
{
    return m_streetDirectionPrefix;
}

void MailingAddress::setStreetDirectionPrefix(const QString &streetDirectionPrefix)
{
    m_streetDirectionPrefix = streetDirectionPrefix;
}

QString MailingAddress::streetNumber() const
{
    return m_streetNumber;
}

void MailingAddress::setStreetNumber(const QString &streetNumber)
{
    m_streetNumber = streetNumber;
}

QString MailingAddress::streetType() const
{
    return m_streetType;
}

void MailingAddress::setStreetType(const QString &streetType)
{
    m_streetType = streetType;
}

QString MailingAddress::streetName() const
{
    return m_streetName;
}

void MailingAddress::setStreetName(const QString &streetName)
{
    m_streetName = streetName;
}

QString MailingAddress::streetDirectionSuffix() const
{
    return m_streetDirectionSuffix;
}

void MailingAddress::setStreetDirectionSuffix(const QString &streetDirectionSuffix)
{
    m_streetDirectionSuffix = streetDirectionSuffix;
}

QString MailingAddress::city() const
{
    return m_city;
}

void MailingAddress::setCity(const QString &city)
{
    m_city = city;
}

QString MailingAddress::provinceState() const
{
    return m_provinceState;
}

void MailingAddress::setProvinceState(const QString &provinceState)
{
    m_provinceState = provinceState;
}

QString MailingAddress::country() const
{
    return m_country;
}

void MailingAddress::setCountry(const QString &country)
{
    m_country = country;
}

QString MailingAddress::postalZip() const
{
    return m_postalZip;
}

void MailingAddress::setPostalZip(const QString &postalZip)
{
    m_postalZip = postalZip;
}

QString MailingAddress::freeFormAddress() const
{
    return m_freeFormAddress;
}

void MailingAddress::setFreeFormAddress(const QString &freeFormAddress)
{
    m_freeFormAddress = freeFormAddress;
}

QString MailingAddress::compartment() const
{
    return m_compartment;
}

void MailingAddress::setCompartment(const QString &compartment)
{
    m_compartment = compartment;
}

QString MailingAddress::deliveryInstallationType() const
{
    return m_deliveryInstallationType;
}

void MailingAddress::setDeliveryInstallationType(const QString &deliveryInstallationType)
{
    m_deliveryInstallationType = deliveryInstallationType;
}

QString MailingAddress::modeOfDelivery() const
{
    return m_modeOfDelivery;
}

void MailingAddress::setModeOfDelivery(const QString &modeOfDelivery)
{
    m_modeOfDelivery = modeOfDelivery;
}

QString MailingAddress::site() const
{
    return m_site;
}

void MailingAddress::setSite(const QString &site)
{
    m_site = site;
}

QString MailingAddress::bulkMailCode() const
{
    return m_bulkMailCode;
}

void MailingAddress::setBulkMailCode(const QString &bulkMailCode)
{
    m_bulkMailCode = bulkMailCode;
}

OwnershipGroup *model::MailingAddress::ownershipGroup() const
{
    return qobject_cast<OwnershipGroup *>(foreignKey(OWNERSHIPGROUP_PROPERTY));
}

void MailingAddress::setOwnershipGroup(OwnershipGroup *group)
{
    setForeignKey(OWNERSHIPGROUP_PROPERTY, group);
}
