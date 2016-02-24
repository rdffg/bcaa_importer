#include "ownergroup.h"

using namespace model;
OwnershipGroup::OwnershipGroup(QObject *parent) : QDjangoModel(parent) {}

QString OwnershipGroup::tenureCode() const { return m_tenureCode; }

void OwnershipGroup::setTenureCode(const QString &value) {
  m_tenureCode = value;
}

QString OwnershipGroup::tenureDescription() const {
  return m_tenureDescription;
}

void OwnershipGroup::setTenureDescription(const QString &value) {
  m_tenureDescription = value;
}

bool OwnershipGroup::assessmentNoticeReturned() const {
  return m_assessmentNoticeReturned;
}

void OwnershipGroup::setAssessmentNoticeReturned(bool returned) {
  m_assessmentNoticeReturned = returned;
}

bool OwnershipGroup::assessmentNoticeSuppressed() const {
  return m_assessmentNoticeSuppressed;
}

void OwnershipGroup::setAssessmentNoticeSuppressed(bool suppressed) {
  m_assessmentNoticeSuppressed = suppressed;
}

QString OwnershipGroup::changeType() const { return m_changeType; }

void OwnershipGroup::setChangeType(QString changeType) {
  m_changeType = changeType;
}

QString OwnershipGroup::changeTypeDescription() const {
  return m_changeSourceDescription;
}

void OwnershipGroup::setChangeTypeDescription(QString descr) {
  m_changeTypeDescription = descr;
}

QDate OwnershipGroup::changeDate() const { return m_changeDate; }

void OwnershipGroup::setChangeDate(QDate date) { m_changeDate = date; }

QString OwnershipGroup::changeSource() const { return m_changeSource; }

void OwnershipGroup::setChangeSource(QString source) {
  m_changeSource = source;
}

QString OwnershipGroup::changeSourceDescription() const {
  return m_changeSourceDescription;
}

void OwnershipGroup::setChangeSourceDescription(QString descr) {
  m_changeSourceDescription = descr;
}

Folio *OwnershipGroup::folio() const {
    return qobject_cast<Folio *>(foreignKey(FOLIO_PROPERTY));
}

void OwnershipGroup::setFolio(Folio *folio) {
    setForeignKey(FOLIO_PROPERTY, folio);
}
