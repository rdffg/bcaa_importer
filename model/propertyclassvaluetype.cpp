#include "propertyclassvaluetype.h"
#include "saveerror.h"
#include <QMetaEnum>
#include "QDjangoQuerySet.h"

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

void PropertyClassValueType::populate()
{
    const QMetaObject &mo = PropertyClassValueType::staticMetaObject;
    int index = mo.indexOfEnumerator("ValueType");
    QMetaEnum metaEnum = mo.enumerator(index);
    QDjangoQuerySet<PropertyClassValueType> query;
    if (query.count() < metaEnum.keyCount())
    {
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
            PropertyClassValueType prop;
            prop.setType(static_cast<ValueType>(i));
            prop.setDescription(metaEnum.valueToKey(i));
            if (!prop.save())
                throw SaveError(prop.lastError().text());
        }
    }
}
