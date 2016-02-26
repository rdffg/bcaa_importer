#include "specialdistrict.h"

using namespace model;
SpecialDistrict::SpecialDistrict(QObject *parent): QDjangoModel (parent)
{

}

QString SpecialDistrict::districtDescription() const
{
    return m_districtDescription;
}

void SpecialDistrict::setDistrictDescription(const QString &districtDescription)
{
    m_districtDescription = districtDescription;
}

QString SpecialDistrict::districtCode() const
{
    return m_districtCode;
}

void SpecialDistrict::setDistrictCode(const QString &districtCode)
{
    m_districtCode = districtCode;
}
