#ifndef MANUALCLASS_H
#define MANUALCLASS_H
#include "QDjangoModel.h"
//#include "DataAdvice.hxx"
#include <memory>


namespace model {
class ManualClass : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString manualClassCode READ manualClassCode WRITE setManualClassCode)
    Q_PROPERTY(QString manualClassDescription READ manualClassDescription WRITE setManualClassDescription)
    Q_PROPERTY(double deviation READ deviation WRITE setDeviation)

    Q_CLASSINFO("__meta__", "db_table=manual_class")
    Q_CLASSINFO("manualClassCode", "null=true")
    Q_CLASSINFO("manualClassDescription", "null=true")

public:
    explicit ManualClass(QObject *parent=0);
    QString manualClassCode() const;
    void setManualClassCode(const QString &manualClassCode);

    QString manualClassDescription() const;
    void setManualClassDescription(const QString &manualClassDescription);

    double deviation() const;
    void setDeviation(double deviation);

//    static std::unique_ptr<ManualClass> fromXml(const dataadvice::ManualClass &mclass);

private:
    QString m_manualClassCode;
    QString m_manualClassDescription;
    double m_deviation;
};
}
#endif // MANUALCLASS_H
