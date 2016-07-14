#include "specialdistrict.h"

using namespace model;
SpecialDistrict::SpecialDistrict(QObject *parent): QDjangoModel (parent)
{

}

QString SpecialDistrict::description() const
{
    return m_districtDescription;
}

void SpecialDistrict::setDescription(const QString &districtDescription)
{
    m_districtDescription = districtDescription;
}

QString SpecialDistrict::code() const
{
    return m_districtCode;
}

void SpecialDistrict::setCode(const QString &districtCode)
{
    m_districtCode = districtCode;
}

//std::unique_ptr<SpecialDistrict> SpecialDistrict::fromXml(const dataadvice::SpecialDistrict &district)
//{
//    auto model = std::make_unique<SpecialDistrict>();
//    if (district.DistrictCode().present())
//        model->setCode(QString::fromStdString(district.DistrictCode().get()));
//    if (district.DistrictDescription().present())
//        model->setDescription(QString::fromStdString(district.DistrictDescription().get()));
//    return model;
//}
