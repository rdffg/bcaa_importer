#include "foliodescription.h"

using namespace model;
FolioDescription::FolioDescription(QObject *parent): QDjangoModel (parent)
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

SpecialDistrict *FolioDescription::regionalDistrict() const
{
    return qobject_cast<SpecialDistrict*>(foreignKey(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY));
}

void FolioDescription::setRegionalDistrict(SpecialDistrict *district)
{
    setForeignKey(FOLIODESCRIPTION_REGIONALDISTRICT_PROPERTY, district);
}

SpecialDistrict* FolioDescription::regionalHospitalDistrict() const
{
    return qobject_cast<SpecialDistrict*>(foreignKey(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY));
}

void FolioDescription::setRegionalHospitalDistrict(SpecialDistrict *district)
{
    setForeignKey(FOLIODESCRIPTION_HOSPITALDISTRICT_PROPERTY, district);
}

std::unique_ptr<FolioDescription> FolioDescription::fromXml(const dataadvice::FolioDescription &descr)
{
    auto model = std::make_unique<FolioDescription>();
    if (descr.ActualUseCode().present())
        model->setActualUseCode(QString::fromStdString(descr.ActualUseCode().get()));
    if (descr.ActualUseDescription().present())
        model->setActualUseDescription(QString::fromStdString(descr.ActualUseDescription().get()));
    if (descr.ALRCode().present())
        model->setAlrCode(QString::fromStdString(descr.ALRCode().get()));
    if (descr.ALRDescription().present())
        model->setAlrDescription(QString::fromStdString(descr.ALRDescription().get()));
    if (descr.BCTransitFlag().present())
        model->setBcTransitFlag(descr.BCTransitFlag().get());
    if (descr.ParkingArea().present())
        model->setParkingArea(QString::fromStdString(descr.ParkingArea().get()));
    if (descr.PoliceTaxFlag().present())
        model->setPoliceTaxFlag(descr.PoliceTaxFlag().get());
    if (descr.VacantFlag().present())
        model->setVacantFlag(descr.VacantFlag().get());
    return model;
}

QString FolioDescription::predominantManualClass() const
{
    return m_predominantManualClass;
}

void FolioDescription::setPredominantManualClass(const QString &predominantManualClass)
{
    m_predominantManualClass = predominantManualClass;
}

model::Folio* FolioDescription::folio() const
{
    return qobject_cast<model::Folio*>(foreignKey(FOLIODESCRIPTION_FOLIO_PROPERTY));
}

void FolioDescription::setFolio(model::Folio* folio)
{
    setForeignKey(FOLIODESCRIPTION_FOLIO_PROPERTY, folio);
}
