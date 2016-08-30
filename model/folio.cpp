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

QString Folio::id() const
{
    return m_id;
}

void Folio::setId(const QString &id)
{
    m_id = id;
}
