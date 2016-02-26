#ifndef SPECIALDISTRICT_H
#define SPECIALDISTRICT_H
#include "QDjangoModel.h"

namespace model {
class SpecialDistrict : public QDjangoModel
{
    Q_OBJECT
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
