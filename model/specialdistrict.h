#ifndef SPECIALDISTRICT_H
#define SPECIALDISTRICT_H
#include "QDjangoModel.h"
#include "DataAdvice.hxx"
#include <memory>

namespace model {
class SpecialDistrict : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString description READ description WRITE setDescription)

    Q_CLASSINFO("__meta__", "db_table=special_district null=true")
    Q_CLASSINFO("code", "null=true")
public:
    explicit SpecialDistrict(QObject *parent=0);
    QString description() const;
    void setDescription(const QString &description);

    QString code() const;
    void setCode(const QString &code);

    static std::unique_ptr<SpecialDistrict> fromXml(const dataadvice::SpecialDistrict &district);

private:
    QString m_districtCode;
    QString m_districtDescription;
};
}
#endif // SPECIALDISTRICT_H
