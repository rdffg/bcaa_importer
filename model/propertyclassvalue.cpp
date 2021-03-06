#include "propertyclassvalue.h"

namespace model {

PropertyClassValue::PropertyClassValue(QObject *parent) : QDjangoModel(parent)
{

}

Valuation *PropertyClassValue::grossValues() const
{
    return qobject_cast<Valuation *>(foreignKey("grossValues"));
}

void PropertyClassValue::setGrossValues(Valuation *valuation)
{
    setForeignKey("grossValues", valuation);
}

void PropertyClassValue::setGrossValues(std::unique_ptr<Valuation> valuation)
{
    m_grossValues = valuation.get();
    setGrossValues(valuation.release());
}

Valuation *PropertyClassValue::taxExemptValues() const
{
    return qobject_cast<Valuation *>(foreignKey("taxExemptValues"));
}

void PropertyClassValue::setTaxExemptValues(Valuation *valuation)
{
    setForeignKey("taxExemptValues", valuation);
}

void PropertyClassValue::setTaxExemptValues(std::unique_ptr<Valuation> valuation)
{
    m_taxExemptValues = valuation.release();
    setTaxExemptValues(m_taxExemptValues);
}

Valuation *PropertyClassValue::netValues() const
{
    return qobject_cast<Valuation *>(foreignKey("netValues"));
}

void PropertyClassValue::setNetValues(Valuation *valuation)
{
    setForeignKey("netValues", valuation);
}

void PropertyClassValue::setNetValues(std::unique_ptr<Valuation> valuation)
{
    m_netValues = valuation.release();
    setNetValues(m_netValues);
}

QString PropertyClassValue::propertyClassCode() const
{
    return m_propertyClassCode;
}

void PropertyClassValue::setPropertyClassCode(const QString &code)
{
    m_propertyClassCode = code;
}

QString PropertyClassValue::propertyClassDescription() const
{
    return m_propertyClassDescription;
}

void PropertyClassValue::setPropertyClassDescription(const QString &description)
{
    m_propertyClassDescription = description;
}

QString PropertyClassValue::propertySubClassCode() const
{
    return m_propertySubClassCode;
}

void PropertyClassValue::setPropertySubClassCode(const QString &code)
{
    m_propertySubClassCode = code;
}

QString PropertyClassValue::propertySubClassDescription() const
{
    return m_propertySubClassDescription;
}

void PropertyClassValue::setPropertySubClassDescription(const QString &description)
{
    m_propertySubClassDescription = description;
}

PropertyClassValueType* PropertyClassValue::valueType() const
{
    return qobject_cast<PropertyClassValueType *>(foreignKey("valueType"));
}

void PropertyClassValue::setValueType(PropertyClassValueType *type)
{
    setForeignKey("valueType", type);
}

void PropertyClassValue::setValueType(std::unique_ptr<PropertyClassValueType> type)
{
    m_valueType = type.release();
    setForeignKey("valueType", m_valueType);
}

Folio *PropertyClassValue::folio() const
{
   return qobject_cast<Folio *>(foreignKey("folio"));
}

void PropertyClassValue::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}


PropertyClassValue::~PropertyClassValue()
{
    delete foreignKey("grossValues");
    delete foreignKey("netValues");
    delete foreignKey("taxExemptValues");
    delete m_valueType;
}
} // namespace model
