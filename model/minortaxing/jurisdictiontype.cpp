#include "jurisdictiontype.h"

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
