#include "foliodescription.h"
#include "model/landmeasurement.h"
#include "model/neighbourhood.h"

using namespace model;
FolioDescription::FolioDescription(QObject *parent):
    QDjangoModel (parent)
{

}

QString FolioDescription::actualUseCode() const
{
    return m_actualUseCode;
}

void FolioDescription::setActualUseCode(const QString &actualUseCode)
{
    m_actualUseCode = actualUseCode;
}

QString FolioDescription::actualUseDescription() const
{
    return m_actualUseDescription;
}

void FolioDescription::setActualUseDescription(const QString &actualUseDescription)
{
    m_actualUseDescription = actualUseDescription;
}

bool FolioDescription::vacantFlag() const
{
    return m_vacantFlag;
}

void FolioDescription::setVacantFlag(bool vacantFlag)
{
    m_vacantFlag = vacantFlag;
}

bool FolioDescription::bcTransitFlag() const
{
    return m_bcTransitFlag;
}

void FolioDescription::setBcTransitFlag(bool bcTransitFlag)
{
    m_bcTransitFlag = bcTransitFlag;
}

bool FolioDescription::policeTaxFlag() const
{
    return m_policeTaxFlag;
}

void FolioDescription::setPoliceTaxFlag(bool policeTaxFlag)
{
    m_policeTaxFlag = policeTaxFlag;
}

QString FolioDescription::alrCode() const
{
    return m_alrCode;
}

void FolioDescription::setAlrCode(const QString &alrCode)
{
    m_alrCode = alrCode;
}

QString FolioDescription::alrDescription() const
{
    return m_alrDescription;
}

void FolioDescription::setAlrDescription(const QString &alrDescription)
{
    m_alrDescription = alrDescription;
}

QString FolioDescription::parkingArea() const
{
    return m_parkingArea;
}

void FolioDescription::setParkingArea(const QString &parkingArea)
{
    m_parkingArea = parkingArea;
}

SpecialDistrict *FolioDescription::schoolDistrict() const
{
    return qobject_cast<model::SpecialDistrict*>(foreignKey(FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY));
}

void FolioDescription::setSchoolDistrict(SpecialDistrict *district)
{
    setForeignKey(FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY, district);
}

void FolioDescription::setSchoolDistrict(std::unique_ptr<SpecialDistrict> district)
{
    setForeignKey(FOLIODESCRIPTION_SCHOOLDISTRICT_PROPERTY, district.get());
}

SpecialDistrict *FolioDescription::regionalDistrict() const
{
    return qobject_cast<SpecialDistrict*>(foreignKey(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY));
}

void FolioDescription::setRegionalDistrict(SpecialDistrict *district)
{
    setForeignKey(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY, district);
}

void FolioDescription::setRegionalDistrict(std::unique_ptr<SpecialDistrict> district)
{
    setForeignKey(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY, district.get());
}

SpecialDistrict* FolioDescription::regionalHospitalDistrict() const
{
    return qobject_cast<SpecialDistrict*>(foreignKey(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY));
}

void FolioDescription::setRegionalHospitalDistrict(SpecialDistrict *district)
{
    setForeignKey(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY, district);
}

void FolioDescription::setRegionalHospitalDistrict(std::unique_ptr<SpecialDistrict> district)
{
    setForeignKey(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY, district.get());
}

QString FolioDescription::tenureCode() const
{
    return m_tenureCode;
}

void FolioDescription::setTenureCode(const QString &tenureCode)
{
    m_tenureCode = tenureCode;
}

QString FolioDescription::tenureDescription() const
{
    return m_tenureDescription;
}

void FolioDescription::setTenureDescription(const QString &tenureDescription)
{
    m_tenureDescription = tenureDescription;
}

ManualClass* FolioDescription::predominantManualClass() const
{
    return qobject_cast<ManualClass *>(foreignKey(FOLIODESCRIPTION_PREDOMINANT_MANUALCLASS));
}

void FolioDescription::setPredominantManualClass(std::unique_ptr<ManualClass> predominantManualClass)
{
    setForeignKey(FOLIODESCRIPTION_PREDOMINANT_MANUALCLASS, predominantManualClass.get());
}

void FolioDescription::setPredominantManualClass(ManualClass *predominantManualClass)
{
    setForeignKey(FOLIODESCRIPTION_PREDOMINANT_MANUALCLASS, predominantManualClass);
}

model::Folio* FolioDescription::folio() const
{
    return qobject_cast<model::Folio*>(foreignKey(FOLIODESCRIPTION_FOLIO_PROPERTY));
}

void FolioDescription::setFolio(model::Folio* folio)
{
    setForeignKey(FOLIODESCRIPTION_FOLIO_PROPERTY, folio);
}

void FolioDescription::setLandMeasurement(std::unique_ptr<model::LandMeasurement> &measurement)
{
    m_measurement = std::move(measurement);
}

std::unique_ptr<model::LandMeasurement>& FolioDescription::landMeasurement()
{
    return m_measurement;
}

void FolioDescription::setNeighbourhood(std::unique_ptr<model::Neighbourhood> &neighbourhood)
{
    m_neighbourhood = std::move(neighbourhood);
}

std::unique_ptr<model::Neighbourhood>& FolioDescription::neighbourhood()
{
    return m_neighbourhood;
}

bool FolioDescription::schoolTax3Mto4MFlag() const
{
    return m_schoolTax3Mto4MFlag;
}

void FolioDescription::setSchoolTax3Mto4MFlag(bool flag)
{
    m_schoolTax3Mto4MFlag = flag;
}

bool FolioDescription::schoolTaxGreater4MFlag() const
{
    return m_schoolTaxGreater4MFlag;
}

void FolioDescription::setSchooTaxGreater4MFlag(bool flag)
{
    m_schoolTaxGreater4MFlag = flag;
}

bool FolioDescription::candidateforSpecTaxFlag() const
{
    return m_candidateforSpecTaxFlag;
}

void FolioDescription::setCandidateforSpecTaxFlag(bool flag)
{
    m_candidateforSpecTaxFlag = flag;
}
