#include "valuation.h"

namespace model {

Valuation::Valuation(QObject *parent) : QDjangoModel(parent)
{

}

double Valuation::landValue() const
{
    return m_landValue;
}

void Valuation::setLandValue(const double &value)
{
    m_landValue = value;
}

double Valuation::improvementValue() const
{
    return m_improvementValue;
}

void Valuation::setImprovementValue(const double &value)
{
    m_improvementValue = value;
}

std::unique_ptr<Valuation> Valuation::fromXml(const dataadvice::Valuation &val)
{
    auto valuation = std::make_unique<Valuation>();
    valuation->setImprovementValue(val.ImprovementValue());
    valuation->setLandValue(val.LandValue());
    return valuation;
}

} // namespace model
