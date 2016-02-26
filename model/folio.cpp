#include "folio.h"

using namespace model;

Folio::Folio(QObject *parent): QDjangoModel(parent) {

}

QString Folio::rollNumber() {
    return m_rollNumber;
}

void Folio::setRollNumber(QString num) {
    m_rollNumber = num;
}

QString Folio::status() {
    return m_status;
}

void Folio::setStatus(QString status) {
    m_status = status;
}

QString Folio::statusDescription() {
    return m_statusDescription;
}

void Folio::setStatusDescription(QString desc) {
    m_statusDescription = desc;
}

Jurisdiction *Folio::jurisdiction() const {
    return qobject_cast<Jurisdiction *>(foreignKey("jurisdiction"));
}

void Folio::setJurisdiction(Jurisdiction *juris) {
    setForeignKey(JURISDICTION_PROPERTY, juris);
}

model::minortaxing::MinorTaxingJurisdiction *Folio::generalService() const
{
    return qobject_cast<model::minortaxing::MinorTaxingJurisdiction*>(foreignKey("generalService"));
}

void Folio::setGeneralService(model::minortaxing::MinorTaxingJurisdiction *service)
{
    setForeignKey("generalService", service);
}

model::minortaxing::MinorTaxingJurisdiction *Folio::islandTrust() const
{
    return qobject_cast<model::minortaxing::MinorTaxingJurisdiction*>(foreignKey("islandTrust"));
}

void Folio::setIslandTrust(model::minortaxing::MinorTaxingJurisdiction *trust)
{
    setForeignKey("islandTrust", trust);
}
