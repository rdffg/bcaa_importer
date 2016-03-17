#ifndef MODEL_PROPERTYCLASSVALUE_H
#define MODEL_PROPERTYCLASSVALUE_H

#include <QDjangoModel.h>
#include "valuation.h"
#include <memory>
#include "DataAdvice.hxx"

namespace model {

class PropertyClassValue : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(model::Valuation* grossValues READ grossValues WRITE setGrossValues)
    Q_PROPERTY(model::Valuation* taxExemptValues READ taxExemptValues WRITE setTaxExemptValues)
    Q_PROPERTY(model::Valuation* netValues READ netValues WRITE setNetValues)
    Q_PROPERTY(QString propertyClassCode READ propertyClassCode WRITE setPropertyClassCode)
    Q_PROPERTY(QString propertySubClassCode READ propertySubClassCode WRITE setPropertySubClassCode)
    Q_PROPERTY(QString propertyClassDescription READ propertyClassDescription WRITE setPropertyClassDescription)
    Q_PROPERTY(QString propertySubClassDescription READ propertySubClassDescription WRITE setPropertySubClassDescription)

    Q_CLASSINFO("__meta__", "db_table=property_class_value")
    Q_CLASSINFO("propertyClassCode", "max_length=64")
    Q_CLASSINFO("propertySubClassCode", "null=true, max_length=64")
    Q_CLASSINFO("propertyClassDescription", "null=true, max_length=255")
    Q_CLASSINFO("propertySubClassDescription", "null=true, max_length=255")
public:
    explicit PropertyClassValue(QObject *parent = 0);
    Valuation *grossValues() const;
    void setGrossValues(Valuation *valuation);
    Valuation *taxExemptValues() const;
    void setTaxExemptValues(Valuation *valuation);
    Valuation *netValues() const;
    void setNetValues(Valuation *valuation);

    QString propertyClassCode() const;
    void setPropertyClassCode(const QString &propertyClassCode);

    QString propertyClassDescription() const;
    void setPropertyClassDescription(const QString &propertyClassDescription);

    QString propertySubClassCode() const;
    void setPropertySubClassCode(const QString &propertySubClassCode);

    QString propertySubClassDescription() const;
    void setPropertySubClassDescription(const QString &propertySubClassDescription);

    static std::unique_ptr<PropertyClassValue> fromXml(const dataadvice::PropertyClassValues &values);

signals:

public slots:
private:
    QString m_propertyClassCode;
    QString m_propertyClassDescription;
    QString m_propertySubClassCode;
    QString m_propertySubClassDescription;
};

} // namespace model

#endif // MODEL_PROPERTYCLASSVALUE_H
