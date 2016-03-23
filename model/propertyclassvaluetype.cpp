#include "propertyclassvaluetype.h"
#include <QMetaEnum>

using namespace model;
PropertyClassValueType::PropertyClassValueType(QObject *parent) : QDjangoModel(parent)
{
}

PropertyClassValueType::ValueType PropertyClassValueType::type() const
{
    return m_type;
}

void PropertyClassValueType::setType(const PropertyClassValueType::ValueType &type)
{
    m_type = type;
}

QString PropertyClassValueType::description() const
{
    return m_description;
}

void PropertyClassValueType::setDescription(const QString &description)
{
    m_description = description;
}

std::unique_ptr<PropertyClassValueType> PropertyClassValueType::fromValueType(const PropertyClassValueType::ValueType &type)
{
    auto meta = QMetaEnum::fromType<model::PropertyClassValueType::ValueType>();
    auto model = std::make_unique<model::PropertyClassValueType>();
    model->setType(type);
    model->setDescription(QString::fromStdString((meta.valueToKey(type))));
    return model;
}
