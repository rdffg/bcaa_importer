#ifndef PROPERTYCLASSVALUETYPE_H
#define PROPERTYCLASSVALUETYPE_H

#include <QDjangoModel.h>
#include <memory>

namespace model {
class PropertyClassValueType : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(ValueType type READ type WRITE setType)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_CLASSINFO("__meta__", "db_table=property_class_value_type")
    Q_CLASSINFO("type", "primary_key=true")
    Q_CLASSINFO("description", "max_length=16")
public:
    explicit PropertyClassValueType(QObject *parent = 0);
    enum ValueType
    {
        BCTransit,
        General,
        School
    };
    Q_ENUM(ValueType)

    ValueType type() const;
    void setType(const ValueType &type);

    QString description() const;
    void setDescription(const QString &description);

    static std::unique_ptr<PropertyClassValueType> fromValueType(const ValueType &type);

private:
    ValueType m_type;
    QString m_description;
};
}
#endif // PROPERTYCLASSVALUETYPE_H
