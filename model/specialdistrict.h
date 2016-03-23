#ifndef SPECIALDISTRICT_H
#define SPECIALDISTRICT_H
#include "QDjangoModel.h"

namespace model {
class SpecialDistrict : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString districtCode READ districtCode WRITE setDistrictCode)
    Q_PROPERTY(QString districtDescription READ districtDescription WRITE setDistrictDescription)
    Q_CLASSINFO("__meta__", "db_table=special_district")
    Q_CLASSINFO("districtCode", "max_length=16")
    Q_CLASSINFO("districtDescription", "null=true, max_length=255")
public:
    explicit SpecialDistrict(QObject *parent=0);
    QString districtDescription() const;
    void setDistrictDescription(const QString &districtDescription);

    QString districtCode() const;
    void setDistrictCode(const QString &districtCode);

private:
    QString m_districtCode;
    QString m_districtDescription;
};
}
#endif // SPECIALDISTRICT_H
