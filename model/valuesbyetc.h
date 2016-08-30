#ifndef MODEL_TAXEXEMPTPROPERTYCLASSVALUE_H
#define MODEL_TAXEXEMPTPROPERTYCLASSVALUE_H

#include <QDjangoModel.h>
#include "ivaluation.h"
#include "folio.h"

namespace model {

class ValuesByETC : public QDjangoModel, IValuation
{
    Q_OBJECT
    Q_PROPERTY(QString taxExemptCode READ taxExemptCode WRITE setTaxExemptCode)
    Q_PROPERTY(QString taxExemptDescription READ taxExemptDescription WRITE setTaxExemptDescription)
    Q_PROPERTY(QString propertyClassCode READ propertyClassCode WRITE setPropertyClassCode)
    Q_PROPERTY(QString propertyClassDescription READ propertyClassDescription WRITE setPropertyClassDescription)
    Q_PROPERTY(double landValue READ landValue WRITE setLandValue)
    Q_PROPERTY(double improvementValue READ improvementValue WRITE setImprovementValue)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=tax_exempt_property_class_value")
    Q_CLASSINFO("taxExemptCode", "null=true")
    Q_CLASSINFO("taxExemptDescription", "null=true")
    Q_CLASSINFO("propertyClassCode", "null=true")
    Q_CLASSINFO("propertyClassDescription", "null=true")
    Q_CLASSINFO("landValue", "null=true")
    Q_CLASSINFO("improvementValue", "null=true")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit ValuesByETC(QObject *parent = 0);

    QString taxExemptCode() const;
    void setTaxExemptCode(const QString &taxExemptCode);

    QString taxExemptDescription() const;
    void setTaxExemptDescription(const QString &taxExemptDescription);

    QString propertyClassCode() const;
    void setPropertyClassCode(const QString &propertyClassCode);

    QString propertyClassDescription() const;
    void setPropertyClassDescription(const QString &propertyClassDescription);

    Folio *folio()  const;
    void setFolio(Folio *folio);

//    static std::unique_ptr<TaxExemptPropertyClassValue> fromXml(dataadvice::ValuesByETC &values);
signals:

public slots:
private:
    QString m_taxExemptCode;
    QString m_taxExemptDescription;
    QString m_propertyClassCode;
    QString m_propertyClassDescription;
    double m_landValue;
    double m_improvementValue;

    // IValuation interface
public:
    double landValue() const override;
    void setLandValue(const double &value) override;
    double improvementValue() const override;
    void setImprovementValue(const double &value) override;
};

} // namespace model

#endif // MODEL_TAXEXEMPTPROPERTYCLASSVALUE_H
