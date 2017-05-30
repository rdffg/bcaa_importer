#ifndef MODEL_PROPERTYCLASSVALUE_H
#define MODEL_PROPERTYCLASSVALUE_H

#include <QDjangoModel.h>
#include "valuation.h"
#include <memory>
#include "propertyclassvaluetype.h"
#include "folio.h"

namespace model {

class PropertyClassValue : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString propertyClassCode READ propertyClassCode WRITE setPropertyClassCode)
    Q_PROPERTY(QString propertySubClassCode READ propertySubClassCode WRITE setPropertySubClassCode)
    Q_PROPERTY(QString propertyClassDescription READ propertyClassDescription WRITE setPropertyClassDescription)
    Q_PROPERTY(QString propertySubClassDescription READ propertySubClassDescription WRITE setPropertySubClassDescription)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)
    Q_PROPERTY(model::PropertyClassValueType *valueType READ valueType WRITE setValueType)
    Q_PROPERTY(model::Valuation *grossValues READ grossValues WRITE setGrossValues)
    Q_PROPERTY(model::Valuation *taxExemptValues READ taxExemptValues WRITE setTaxExemptValues)
    Q_PROPERTY(model::Valuation *netValues READ netValues WRITE setNetValues)

    Q_CLASSINFO("__meta__", "db_table=property_class_value")
    Q_CLASSINFO("propertyClassCode", "max_length=64")
    Q_CLASSINFO("propertySubClassCode", "null=true max_length=64")
    Q_CLASSINFO("propertyClassDescription", "null=true max_length=255")
    Q_CLASSINFO("propertySubClassDescription", "null=true max_length=255")
    Q_CLASSINFO("grossValues", "null=true on_delete=cascade")
    Q_CLASSINFO("taxExemptValues", "null=true on_delete=cascade")
    Q_CLASSINFO("netValues", "null=true on_delete=cascade")
    Q_CLASSINFO("folio", "on_delete=cascade")

public:

    explicit PropertyClassValue(QObject *parent = 0);
    Valuation *grossValues() const;
    void setGrossValues(std::unique_ptr<Valuation> valuation);

    Valuation *taxExemptValues() const;
    void setTaxExemptValues(std::unique_ptr<Valuation> valuation);

    Valuation *netValues() const;
    void setNetValues(std::unique_ptr<Valuation> valuation);

    QString propertyClassCode() const;
    void setPropertyClassCode(const QString &propertyClassCode);

    QString propertyClassDescription() const;
    void setPropertyClassDescription(const QString &propertyClassDescription);

    QString propertySubClassCode() const;
    void setPropertySubClassCode(const QString &propertySubClassCode);

    QString propertySubClassDescription() const;
    void setPropertySubClassDescription(const QString &propertySubClassDescription);

    PropertyClassValueType* valueType()  const;
    void setValueType(std::unique_ptr<PropertyClassValueType> type);

    Folio* folio() const;
    void setFolio(Folio *folio);

    ~PropertyClassValue();

signals:

public slots:
private:
    void setValueType(PropertyClassValueType *type);
    void setTaxExemptValues(Valuation *valuation);
    void setGrossValues(Valuation *valuation);
    void setNetValues(Valuation *valuation);
    QString m_propertyClassCode;
    QString m_propertyClassDescription;
    QString m_propertySubClassCode;
    QString m_propertySubClassDescription;
    model::Valuation* m_grossValues;
    model::Valuation* m_netValues;
    model::Valuation* m_taxExemptValues;
    model::PropertyClassValueType* m_valueType;
};

} // namespace model

#endif // MODEL_PROPERTYCLASSVALUE_H
