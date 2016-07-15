#ifndef FOLIODESCRIPTION_H
#define FOLIODESCRIPTION_H
#include "QDjangoModel.h"
#include "model/folio.h"
#include "model/specialdistrict.h"
#include "model/manualclass.h"

#define FOLIODESCRIPTION_FOLIO_PROPERTY "folio"
#define FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY "schoolDistrict"
#define FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY "regionalDistrict"
#define FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY "regionalHospitalDistrict"
#define FOLIODESCRIPTION_PREDOMINANT_MANUALCLASS "predominantManualClass"
namespace model {

class LandMeasurement;
class Neighbourhood;

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
    Q_PROPERTY(QString tenureCode READ tenureCode WRITE setTenureCode)
    Q_PROPERTY(QString tenureDescription READ tenureDescription WRITE setTenureDescription)
    Q_PROPERTY(model::SpecialDistrict *schoolDistrict READ schoolDistrict WRITE setSchoolDistrict)
    Q_PROPERTY(model::SpecialDistrict *regionalDistrict READ regionalDistrict WRITE setRegionalDistrict)
    Q_PROPERTY(model::SpecialDistrict *regionalHospitalDistrict READ regionalHospitalDistrict WRITE setRegionalHospitalDistrict)
    Q_PROPERTY(model::ManualClass *predominantManualClass READ predominantManualClass WRITE setPredominantManualClass)
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
    Q_CLASSINFO("tenureCode", "null=true")
    Q_CLASSINFO("tenureDescription", "null=true")
    Q_CLASSINFO(FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY, "null=true on_delete=setnull")
    Q_CLASSINFO(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY, "on_delete=setnull null=true")
    Q_CLASSINFO(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY, "null=true on_delete=setnull")
    Q_CLASSINFO(FOLIODESCRIPTION_PREDOMINANT_MANUALCLASS, "null=true on_delete=setnull")
    Q_CLASSINFO("predominantManualClass", "null=true on_delete=setnull")
    Q_CLASSINFO("folio", "on_delete=cascade")

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

    ManualClass *predominantManualClass() const;
    void setPredominantManualClass(ManualClass *predominantManualClass);
    void setPredominantManualClass(std::unique_ptr<ManualClass> predominantManualClass);

    model::Folio* folio() const;
    void setFolio(model::Folio* folio);

    model::SpecialDistrict* schoolDistrict() const;
    void setSchoolDistrict(SpecialDistrict *district);
    void setSchoolDistrict(std::unique_ptr<SpecialDistrict> district);

    model::SpecialDistrict* regionalDistrict() const;
    void setRegionalDistrict(SpecialDistrict *district);
    void setRegionalDistrict(std::unique_ptr<SpecialDistrict> district);

    model::SpecialDistrict* regionalHospitalDistrict() const;
    void setRegionalHospitalDistrict(SpecialDistrict* district);
    void setRegionalHospitalDistrict(std::unique_ptr<SpecialDistrict> district);

    QString tenureCode() const;
    void setTenureCode(const QString &tenureCode);

    QString tenureDescription() const;
    void setTenureDescription(const QString &tenureDescription);

    // storage for child objects
    void setLandMeasurement(std::unique_ptr<model::LandMeasurement> &measurement);
    std::unique_ptr<model::LandMeasurement>& landMeasurement();
    void setNeighbourhood(std::unique_ptr<model::Neighbourhood> &neighbourhood);
    std::unique_ptr<model::Neighbourhood>& neighbourhood();

private:
    QString m_actualUseCode;
    QString m_actualUseDescription;
    bool m_vacantFlag;
    bool m_bcTransitFlag;
    bool m_policeTaxFlag;
    QString m_alrCode;
    QString m_alrDescription;
    QString m_parkingArea;
    QString m_tenureCode;
    QString m_tenureDescription;
    std::unique_ptr<model::LandMeasurement> m_measurement;
    std::unique_ptr<model::Neighbourhood> m_neighbourhood;
};
}

#endif // FOLIODESCRIPTION_H
