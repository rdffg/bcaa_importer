#include "minortaxingjurisdiction.h"

using namespace model::minortaxing;
MinorTaxingJurisdiction::MinorTaxingJurisdiction(QObject *parent): QDjangoModel(parent)
{
}

QString MinorTaxingJurisdiction::code() const
{
    return m_code;
}

void MinorTaxingJurisdiction::setCode(const QString &code)
{
    m_code = code;
}

QString MinorTaxingJurisdiction::shortCode() const
{
    return m_shortCode;
}

void MinorTaxingJurisdiction::setShortCode(const QString &shortCode)
{
    m_shortCode = shortCode;
}

QString MinorTaxingJurisdiction::minorTaxingDescription() const
{
    return m_minorTaxingDescription;
}

void MinorTaxingJurisdiction::setMinorTaxingDescription(const QString &minorTaxingDescription)
{
    m_minorTaxingDescription = minorTaxingDescription;
}
