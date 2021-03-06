#include "valuesbyetc.h"

namespace model {

ValuesByETC::ValuesByETC(QObject *parent) : QDjangoModel(parent)
{

}

QString ValuesByETC::taxExemptCode() const
{
    return m_taxExemptCode;
}

void ValuesByETC::setTaxExemptCode(const QString &taxExemptCode)
{
    m_taxExemptCode = taxExemptCode;
}

QString ValuesByETC::taxExemptDescription() const
{
    return m_taxExemptDescription;
}

void ValuesByETC::setTaxExemptDescription(const QString &taxExemptDescription)
{
    m_taxExemptDescription = taxExemptDescription;
}

QString ValuesByETC::propertyClassCode() const
{
    return m_propertyClassCode;
}

void ValuesByETC::setPropertyClassCode(const QString &propertyClassCode)
{
    m_propertyClassCode = propertyClassCode;
}

QString ValuesByETC::propertyClassDescription() const
{
    return m_propertyClassDescription;
}

void ValuesByETC::setPropertyClassDescription(const QString &propertyClassDescription)
{
    m_propertyClassDescription = propertyClassDescription;
}

double ValuesByETC::landValue() const
{
    return m_landValue;
}

void ValuesByETC::setLandValue(const double &value)
{
    m_landValue = value;
}

double ValuesByETC::improvementValue() const
{
    return m_improvementValue;
}

void ValuesByETC::setImprovementValue(const double &value)
{
    m_improvementValue = value;
}

Folio *ValuesByETC::folio() const
{
    return qobject_cast<Folio*>(foreignKey("folio"));
}

void ValuesByETC::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

//std::unique_ptr<TaxExemptPropertyClassValue> TaxExemptPropertyClassValue::fromXml(dataadvice::ValuesByETC &values)
//{
//    auto model = std::make_unique<TaxExemptPropertyClassValue>();
//    model->setTaxExemptCode(QString::fromStdString(values.TaxExemptCode()));
//    if (values.TaxExemptDescription().present())
//        model->setTaxExemptDescription(QString::fromStdString(values.TaxExemptDescription().get()));
//    model->setPropertyClassCode(QString::fromStdString(values.PropertyClassCode()));
//    if (values.PropertyClassDescription().present())
//        model->setPropertyClassDescription(QString::fromStdString(values.PropertyClassDescription().get()));
//    model->setLandValue(values.LandValue());
//    model->setImprovementValue(values.ImprovementValue());
//    return model;
//}


} // namespace model
