#include "taxexemptpropertyclassvalue.h"

namespace model {

TaxExemptPropertyClassValue::TaxExemptPropertyClassValue(QObject *parent) : QDjangoModel(parent)
{

}

QString TaxExemptPropertyClassValue::taxExemptCode() const
{
    return m_taxExemptCode;
}

void TaxExemptPropertyClassValue::setTaxExemptCode(const QString &taxExemptCode)
{
    m_taxExemptCode = taxExemptCode;
}

QString TaxExemptPropertyClassValue::taxExemptDescription() const
{
    return m_taxExemptDescription;
}

void TaxExemptPropertyClassValue::setTaxExemptDescription(const QString &taxExemptDescription)
{
    m_taxExemptDescription = taxExemptDescription;
}

QString TaxExemptPropertyClassValue::propertyClassCode() const
{
    return m_propertyClassCode;
}

void TaxExemptPropertyClassValue::setPropertyClassCode(const QString &propertyClassCode)
{
    m_propertyClassCode = propertyClassCode;
}

QString TaxExemptPropertyClassValue::propertyClassDescription() const
{
    return m_propertyClassDescription;
}

void TaxExemptPropertyClassValue::setPropertyClassDescription(const QString &propertyClassDescription)
{
    m_propertyClassDescription = propertyClassDescription;
}

double TaxExemptPropertyClassValue::landValue() const
{
    return m_landValue;
}

void TaxExemptPropertyClassValue::setLandValue(const double &value)
{
    m_landValue = value;
}

double TaxExemptPropertyClassValue::improvementValue() const
{
    return m_improvementValue;
}

void TaxExemptPropertyClassValue::setImprovementValue(const double &value)
{
    m_improvementValue = value;
}

Folio *TaxExemptPropertyClassValue::folio() const
{
    return qobject_cast<Folio*>(foreignKey("folio"));
}

void TaxExemptPropertyClassValue::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

std::unique_ptr<TaxExemptPropertyClassValue> TaxExemptPropertyClassValue::fromXml(dataadvice::TaxExemptPropertyClassValues &values)
{
    auto model = std::make_unique<TaxExemptPropertyClassValue>();
    model->setTaxExemptCode(QString::fromStdString(values.TaxExemptCode()));
    if (values.TaxExemptDescription().present())
        model->setTaxExemptDescription(QString::fromStdString(values.TaxExemptDescription().get()));
    model->setPropertyClassCode(QString::fromStdString(values.PropertyClassCode()));
    if (values.PropertyClassDescription().present())
        model->setPropertyClassDescription(QString::fromStdString(values.PropertyClassDescription().get()));
    model->setLandValue(values.LandValue());
    model->setImprovementValue(values.ImprovementValue());
    return model;
}


} // namespace model
