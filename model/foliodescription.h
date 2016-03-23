#ifndef FOLIODESCRIPTION_H
#define FOLIODESCRIPTION_H
#include "QDjangoModel.h"
#include "model/folio.h"
#include "model/specialdistrict.h"
#include "model/manualclass.h"

#define FOLIODESCRIPTION_FOLIO_PROPERTY "folio"
#define FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY "folio"
#define FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY "folio"
#define FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY "folio"
namespace model {
class FolioDescription : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString actualUseCode READ actualUseCode WRITE setActualUseCode)
    Q_PROPERTY(QString actualUseDescription READ actualUseDescription WRITE setActualUseDescription)
    Q_PROPERTY(bool vacantFlag READ vacantFlag WRITE setVacantFlag)
    Q_PROPERTY(bool bcTransitFlag READ bcTransitFlag WRITE setBcTransitFlag)
    Q_PROPERTY(bool policeTaxFlag READ policeTaxFlag WRITE setPoliceTaxFlag)
    Q_PROPERTY(QString alrCode READ alrCode WRITE setAlrCode)
    Q_PROPERTY(QString alrDescription READ alrDescription WRITE setAlrDescription)
    Q_PROPERTY(QString parkingArea READ parkingArea WRITE setParkingArea)
    Q_PROPERTY(model::SpecialDistrict *schoolDistrict READ schoolDistrict WRITE setSchoolDistrict)
    Q_PROPERTY(model::SpecialDistrict *regionalDistrict READ regionalDistrict WRITE setRegionalDistrict)
    Q_PROPERTY(model::SpecialDistrict *regionalHospitalDistrict READ regionalHospitalDistrict WRITE setRegionalHospitalDistrict)
    Q_PROPERTY(QString predominantManualClass READ predominantManualClass WRITE setPredominantManualClass)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=folio_description")
    Q_CLASSINFO("actualUseCode", "null=true")
    Q_CLASSINFO("actualUseDescription", "null=true")
    Q_CLASSINFO("vacantFlag", "null=true")
    Q_CLASSINFO("bcTransitFlag", "null=true")
    Q_CLASSINFO("policeTaxFlag", "null=true")
    Q_CLASSINFO("alrCode", "null=true")
    Q_CLASSINFO("alrDescription", "null=true")
    Q_CLASSINFO("parkingArea", "null=true")
    Q_CLASSINFO(FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY, "null=true")
    Q_CLASSINFO(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY, "null=true")
    Q_CLASSINFO(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY, "null=true")
    Q_CLASSINFO("predominantManualClass", "null=true")
    Q_CLASSINFO("folio", "null=true")

public:
    explicit FolioDescription(QObject *parent=0);

    QString actualUseCode() const;
    void setActualUseCode(const QString &actualUseCode);

    QString actualUseDescription() const;
    void setActualUseDescription(const QString &actualUseDescription);

    bool vacantFlag() const;
    void setVacantFlag(bool vacantFlag);

    bool bcTransitFlag() const;
    void setBcTransitFlag(bool bcTransitFlag);

    bool policeTaxFlag() const;
    void setPoliceTaxFlag(bool policeTaxFlag);

    QString alrCode() const;
    void setAlrCode(const QString &alrCode);

    QString alrDescription() const;
    void setAlrDescription(const QString &alrDescription);

    QString parkingArea() const;
    void setParkingArea(const QString &parkingArea);

    QString predominantManualClass() const;
    void setPredominantManualClass(const QString &predominantManualClass);

    model::Folio* folio() const;
    void setFolio(model::Folio* folio);

    model::SpecialDistrict* schoolDistrict() const;
    void setSchoolDistrict(SpecialDistrict *district);

    model::SpecialDistrict* regionalDistrict() const;
    void setRegionalDistrict(SpecialDistrict *district);

    model::SpecialDistrict* regionalHospitalDistrict() const;
    void setRegionalHospitalDistrict(SpecialDistrict* district);

    static std::unique_ptr<FolioDescription> fromXml(const dataadvice::FolioDescription &descr);

private:
    QString m_actualUseCode;
    QString m_actualUseDescription;
    bool m_vacantFlag;
    bool m_bcTransitFlag;
    bool m_policeTaxFlag;
    QString m_alrCode;
    QString m_alrDescription;
    QString m_parkingArea;
    QString m_predominantManualClass;
};
}

#endif // FOLIODESCRIPTION_H
