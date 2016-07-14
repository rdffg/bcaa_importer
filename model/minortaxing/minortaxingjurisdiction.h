#ifndef MINORTAXINGJURISDICTION_H
#define MINORTAXINGJURISDICTION_H
#include "QDjangoModel.h"
#include "jurisdictiontype.h"
//#include "DataAdvice.hxx"
#include <memory>

namespace model {
namespace minortaxing {
class MinorTaxingJurisdiction : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString ID READ ID WRITE setID)
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString shortCode READ shortCode WRITE setShortCode)
    Q_PROPERTY(QString minorTaxingDescription READ minorTaxingDescription WRITE setMinorTaxingDescription)
    Q_PROPERTY(model::minortaxing::JurisdictionType *jurisdictionType READ jurisdictionType WRITE setJurisdictionType)

    Q_CLASSINFO("__meta__", "db_table=minor_taxing_jurisdiction")
    Q_CLASSINFO("ID", "primary_key=true max_length=32")
    Q_CLASSINFO("code", "null=true")
    Q_CLASSINFO("shortCode", "null=true")
    Q_CLASSINFO("minorTaxingDescription", "null=true")
    Q_CLASSINFO("jurisdictionType", "on_delete=setnull")

public:
    explicit MinorTaxingJurisdiction(QObject *parent=0);

    QString ID() const;
    void setID(const QString &id);

    QString code() const;
    void setCode(const QString &code);

    QString shortCode() const;
    void setShortCode(const QString &shortCode);

    QString minorTaxingDescription() const;
    void setMinorTaxingDescription(const QString &minorTaxingDescription);

    JurisdictionType *jurisdictionType() const;
    void setJurisdictionType(JurisdictionType *type);

    void setJurisdictionType(std::unique_ptr<JurisdictionType> type);

private:
    QString m_id;
    QString m_code;
    QString m_shortCode;
    QString m_minorTaxingDescription;
};
}
}
#endif // MINORTAXINGJURISDICTION_H
