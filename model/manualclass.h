#ifndef MANUALCLASS_H
#define MANUALCLASS_H
#include "QDjangoModel.h"


namespace model {
class ManualClass : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString manualClassCode READ manualClassCode WRITE setManualClassCode)
    Q_PROPERTY(QString manualClassDescription READ manualClassDescription WRITE setManualClassDescription)

    Q_CLASSINFO("__meta__", "db_table=manual_class")
    Q_CLASSINFO("manualClassCode", "null=true")
    Q_CLASSINFO("manualClassDescription", "null=true")

public:
    explicit ManualClass(QObject *parent);
    QString manualClassCode() const;
    void setManualClassCode(const QString &manualClassCode);

    QString manualClassDescription() const;
    void setManualClassDescription(const QString &manualClassDescription);

private:
    QString m_manualClassCode;
    QString m_manualClassDescription;
    float m_deviation;
};
}
#endif // MANUALCLASS_H
