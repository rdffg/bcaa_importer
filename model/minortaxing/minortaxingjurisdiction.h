#ifndef MINORTAXINGJURISDICTION_H
#define MINORTAXINGJURISDICTION_H
#include "QDjangoModel.h"

namespace model {
namespace minortaxing {
class MinorTaxingJurisdiction : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString shortCode READ shortCode WRITE setShortCode)
    Q_PROPERTY(QString minorTaxingDescription READ minorTaxingDescription WRITE setMinorTaxingDescription)

    Q_CLASSINFO("__meta__", "db_table=minor_taxing_jurisdiction")
    Q_CLASSINFO("code", "null=true")
    Q_CLASSINFO("shortCode", "null=true")
    Q_CLASSINFO("minorTaxingDescription", "null=true")

public:
    explicit MinorTaxingJurisdiction(QObject *parent=0);
    QString code() const;
    void setCode(const QString &code);

    QString shortCode() const;
    void setShortCode(const QString &shortCode);

    QString minorTaxingDescription() const;
    void setMinorTaxingDescription(const QString &minorTaxingDescription);

private:
    QString m_code;
    QString m_shortCode;
    QString m_minorTaxingDescription;
};
}
}
#endif // MINORTAXINGJURISDICTION_H
