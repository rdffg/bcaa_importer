#ifndef MAILINGADDRESS_H
#define MAILINGADDRESS_H
#include "QDjangoModel.h"
#include "ownergroup.h"

#define OWNERSHIPGROUP_PROPERTY "ownershipGroup"

namespace model {
class MailingAddress : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString attention READ attention WRITE setAttention)
    Q_PROPERTY(QString careOf READ careOf WRITE setCareOf)
    Q_PROPERTY(QString floor READ floor WRITE setFloor)
    Q_PROPERTY(QString unitNumber READ unitNumber WRITE setUnitNumber)
    Q_PROPERTY(QString streetDirectionPrefix READ streetDirectionPrefix WRITE setStreetDirectionPrefix)
    Q_PROPERTY(QString streetNumber READ streetNumber WRITE setStreetNumber)
    Q_PROPERTY(QString streetType READ streetType WRITE setStreetType)
    Q_PROPERTY(QString streetName READ streetName WRITE setStreetName)
    Q_PROPERTY(QString streetDirectionSuffix READ streetDirectionSuffix WRITE setStreetDirectionSuffix)
    Q_PROPERTY(QString city READ city WRITE setCity)
    Q_PROPERTY(QString provinceState READ provinceState WRITE setProvinceState)
    Q_PROPERTY(QString country READ country WRITE setCountry)
    Q_PROPERTY(QString postalZip READ postalZip WRITE setPostalZip)
    Q_PROPERTY(QString freeFormAddress READ freeFormAddress WRITE setFreeFormAddress)
    Q_PROPERTY(QString compartment READ compartment WRITE setCompartment)
    Q_PROPERTY(QString deliveryInstallationType READ deliveryInstallationType WRITE setDeliveryInstallationType)
    Q_PROPERTY(QString modeOfDelivery READ modeOfDelivery WRITE setModeOfDelivery)
    Q_PROPERTY(QString modeOfDeliveryValue READ modeOfDeliveryValue WRITE setModeOfDeliveryValue)
    Q_PROPERTY(QString site READ site WRITE setSite)
    Q_PROPERTY(QString bulkMailCode READ bulkMailCode WRITE setBulkMailCode)
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(model::OwnershipGroup* ownershipGroup READ ownershipGroup WRITE setOwnershipGroup)

    Q_CLASSINFO("__meta__", "db_table=mailing_address")
    Q_CLASSINFO("attention", "null=true")
    Q_CLASSINFO("careOf", "null=true")
    Q_CLASSINFO("floor", "null=true")
    Q_CLASSINFO("unitNumber", "null=true")
    Q_CLASSINFO("streetDirectionPrefix", "null=true")
    Q_CLASSINFO("streetNumber", "null=true")
    Q_CLASSINFO("streetType", "null=true")
    Q_CLASSINFO("streetName", "null=true")
    Q_CLASSINFO("streetDirectionSuffix", "null=true")
    Q_CLASSINFO("city", "null=true")
    Q_CLASSINFO("provinceState", "null=true")
    Q_CLASSINFO("country", "null=true")
    Q_CLASSINFO("postalZip", "null=true")
    Q_CLASSINFO("freeFormAddress", "null=true")
    Q_CLASSINFO("compartment", "null=true")
    Q_CLASSINFO("deliveryInstallationType", "null=true")
    Q_CLASSINFO("modeOfDelivery", "null=true")
    Q_CLASSINFO("modeOfDeliveryValue", "null=true length=255")
    Q_CLASSINFO("site", "null=true")
    Q_CLASSINFO("bulkMailCode", "null=true")
    Q_CLASSINFO("id", "primary_key=true length=32")
    Q_CLASSINFO(OWNERSHIPGROUP_PROPERTY, "on_delete=cascade")

public:
    explicit MailingAddress(QObject *parent=0);
    QString attention() const;
    void setAttention(const QString &attention);

    QString careOf() const;
    void setCareOf(const QString &careOf);

    QString floor() const;
    void setFloor(const QString &floor);

    QString unitNumber() const;
    void setUnitNumber(const QString &unitNumber);

    QString streetDirectionPrefix() const;
    void setStreetDirectionPrefix(const QString &streetDirectionPrefix);

    QString streetNumber() const;
    void setStreetNumber(const QString &streetNumber);

    QString streetType() const;
    void setStreetType(const QString &streetType);

    QString streetName() const;
    void setStreetName(const QString &streetName);

    QString streetDirectionSuffix() const;
    void setStreetDirectionSuffix(const QString &streetDirectionSuffix);

    QString city() const;
    void setCity(const QString &city);

    QString provinceState() const;
    void setProvinceState(const QString &provinceState);

    QString country() const;
    void setCountry(const QString &country);

    QString postalZip() const;
    void setPostalZip(const QString &postalZip);

    QString freeFormAddress() const;
    void setFreeFormAddress(const QString &freeFormAddress);

    QString compartment() const;
    void setCompartment(const QString &compartment);

    QString deliveryInstallationType() const;
    void setDeliveryInstallationType(const QString &deliveryInstallationType);

    QString modeOfDelivery() const;
    void setModeOfDelivery(const QString &modeOfDelivery);

    QString site() const;
    void setSite(const QString &site);

    QString bulkMailCode() const;
    void setBulkMailCode(const QString &bulkMailCode);

    OwnershipGroup* ownershipGroup() const;
    void setOwnershipGroup(OwnershipGroup *group);

    QString modeOfDeliveryValue() const;
    void setModeOfDeliveryValue(const QString &modeOfDeliveryValue);

    QString id() const;
    void setId(const QString &id);

private:
    QString m_id;
    QString m_attention;
    QString m_careOf;
    QString m_floor;
    QString m_unitNumber;
    QString m_streetDirectionPrefix;
    QString m_streetNumber;
    QString m_streetName;
    QString m_streetType;
    QString m_streetDirectionSuffix;
    QString m_city;
    QString m_provinceState;
    QString m_country;
    QString m_postalZip;
    QString m_freeFormAddress;
    QString m_compartment;
    QString m_deliveryInstallationType;
    QString m_modeOfDelivery;
    QString m_modeOfDeliveryValue;
    QString m_site;
    QString m_bulkMailCode;
};
}

#endif // MAILINGADDRESS_H
