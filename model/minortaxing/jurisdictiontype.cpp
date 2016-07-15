#include "jurisdictiontype.h"
#include "saveerror.h"
#include <QMetaEnum>
#include <QDjangoQuerySet.h>

using namespace model::minortaxing;
JurisdictionType::JurisdictionType(QObject *parent) : QDjangoModel(parent) {}

JurisdictionType::TaxingJurisdictionType JurisdictionType::type() const { return m_type; }

void JurisdictionType::setType(const TaxingJurisdictionType &type) {
  m_type = type;
}

QString JurisdictionType::description() const
{
    return m_description;
}

void JurisdictionType::setDescription(const QString &description)
{
    m_description = description;
}

void JurisdictionType::populate()
{
    const QMetaObject &mo = JurisdictionType::staticMetaObject;
    int index = mo.indexOfEnumerator("TaxingJurisdictionType");
    QMetaEnum metaEnum = mo.enumerator(index);
    QDjangoQuerySet<JurisdictionType> query;
    if (query.count() < metaEnum.keyCount())
    {
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
            JurisdictionType prop;
            prop.setType(static_cast<TaxingJurisdictionType>(i));
            prop.setDescription(metaEnum.valueToKey(i));
            if (!prop.save())
                throw SaveError(prop.lastError().text());
        }
    }
}

std::unique_ptr<JurisdictionType> JurisdictionType::getModel(TaxingJurisdictionType type)
{
    const QMetaObject &mo = JurisdictionType::staticQtMetaObject;
    int index = mo.indexOfEnumerator("TaxingJurisdictionType");
    QMetaEnum metaEnum = mo.enumerator(index);
    auto model = std::make_unique<JurisdictionType>();
    model->setType(type);
    model->setDescription(metaEnum.valueToKey(type));
    return std::move(model);
}
