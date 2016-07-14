#ifndef FOLIOADDRESS_H
#define FOLIOADDRESS_H

#include <QObject>
#include <QDjangoModel.h>
#include "folio.h"
//#include "DataAdvice.hxx"

#define FOLIO_PROPERTY "folio"
namespace model {
/**
 * @brief The FolioAddress class
 *
 * Contains a complete street address of a folio.
 */
class FolioAddress : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(bool primaryFlag READ primaryFlag WRITE setPrimaryFlag)
    Q_PROPERTY(QString unitNumber READ unitNumber WRITE setUnitNumber )
    Q_PROPERTY(QString streetNumber READ streetNumber WRITE setStreetNumber )
    Q_PROPERTY(QString streetDirectionPrefix READ streetDirectionPrefix WRITE setStreetDirectionPrefix )
    Q_PROPERTY(QString streetName READ streetName WRITE setStreetName )
    Q_PROPERTY(QString streetDirectionSuffix READ streetDirectionSuffix WRITE setStreetDirectionSuffix )
    Q_PROPERTY(QString city READ city WRITE setCity )
    Q_PROPERTY(QString provinceState READ provinceState WRITE setProvinceState)
    Q_PROPERTY(QString postalCode READ postalCode WRITE setPostalCode )
    Q_PROPERTY(QString mapReferenceNumber READ mapReferenceNumber WRITE setMapReferenceNumber )
    Q_PROPERTY(QString streetType READ streetType WRITE setStreetType)
    Q_PROPERTY(model::Folio * folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=folio_address")
    Q_CLASSINFO("primaryFlag", "null=true")
    Q_CLASSINFO("unitNumber", "null=true")
    Q_CLASSINFO("streetNumber", "null=true")
    Q_CLASSINFO("streetDirectionPrefix", "null=true")
    Q_CLASSINFO("streetName", "null=true")
    Q_CLASSINFO("streetType", "null=true")
    Q_CLASSINFO("streetDirectionSuffix", "null=true")
    Q_CLASSINFO("city", "null=true")
    Q_CLASSINFO("postalCode", "null=true")
    Q_CLASSINFO("mapReferenceNumber", "null=true")
    Q_CLASSINFO("provinceState", "null=true")
    Q_CLASSINFO(FOLIO_PROPERTY, "on_delete=cascade")

public:
    explicit FolioAddress(QObject *parent = 0);
    bool primaryFlag();
    void setPrimaryFlag(bool flag);

    QString unitNumber();
    void setUnitNumber(QString unit);

    QString streetNumber();
    void setStreetNumber(QString streetnum);

    QString streetDirectionPrefix();
    void setStreetDirectionPrefix(QString prefix);

    QString streetName();
    void setStreetName(QString name);

    QString streetType();
    void setStreetType(QString type);

    QString streetDirectionSuffix();
    void setStreetDirectionSuffix(QString suffix);

    QString city();
    void setCity(QString city);

    QString postalCode();
    void setPostalCode(QString code);

    QString mapReferenceNumber();
    void setMapReferenceNumber(QString mapref);

    Folio *folio();
    void setFolio(Folio *folio);

//    FolioAddress(FolioAddress &&);

//    static FolioAddress *fromXml(dataadvice::FolioAddress const &address);

    QString provinceState() const;
    void setProvinceState(const QString &provinceState);

signals:

public slots:
private:
    bool m_primaryFlag;
    QString m_unit;
    QString m_streetno;
    QString m_streetdirpre;
    QString m_streetname;
    QString m_streetdirsuff;
    QString m_city;
    QString m_postalcode;
    QString m_mapref;
    QString m_streettype;
    QString m_provinceState;
};
}
#endif // FOLIOADDRESS_H
