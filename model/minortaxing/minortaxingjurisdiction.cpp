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

JurisdictionType *MinorTaxingJurisdiction::jurisdictionType() const
{
    return qobject_cast<JurisdictionType *>(foreignKey("jurisdictionType"));
}

void MinorTaxingJurisdiction::setJurisdictionType(JurisdictionType *type)
{
    setForeignKey("jurisdictionType", type);
}

std::unique_ptr<MinorTaxingJurisdiction> MinorTaxingJurisdiction::fromXml(const dataadvice::MinorTaxingJurisdiction &taxing)
{
    auto mtaxing = std::make_unique<model::minortaxing::MinorTaxingJurisdiction>();
    if (taxing.MinorTaxingCode().present())
        mtaxing->setCode(QString::fromStdString(taxing.MinorTaxingCode().get()));
    if (taxing.MinorTaxingCodeShort().present())
        mtaxing->setShortCode(QString::fromStdString(taxing.MinorTaxingCodeShort().get()));
    if (taxing.MinorTaxingDescription().present())
        mtaxing->setMinorTaxingDescription(QString::fromStdString(taxing.MinorTaxingDescription().get()));
    return mtaxing;
}
