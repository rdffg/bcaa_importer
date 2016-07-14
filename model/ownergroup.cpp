#include "ownergroup.h"

using namespace model;
OwnershipGroup::OwnershipGroup(QObject *parent) : QDjangoModel(parent)
    , m_owners(std::vector<std::unique_ptr<model::Owner>>())
    , m_addresses(std::vector<std::unique_ptr<model::FormattedMailingAddress>>())
{}

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

std::vector<std::unique_ptr<Owner>>& OwnershipGroup::owners()
{
    return m_owners;
}

void OwnershipGroup::setOwners(std::vector<std::unique_ptr<model::Owner>> &owners)
{
    m_owners = std::move(owners);
}

std::vector<std::unique_ptr<model::FormattedMailingAddress> >& OwnershipGroup::formattedMailingAddresses()
{
    return m_addresses;
}

void OwnershipGroup::setFormattedMailingAddresses(std::vector<std::unique_ptr<model::FormattedMailingAddress> > &addresses)
{
    m_addresses = std::move(addresses);
}

//model::OwnershipGroup *OwnershipGroup::fromXml(const dataadvice::OwnershipGroup &group) {
//    auto groupmodel = new model::OwnershipGroup();
//    groupmodel->setAssessmentNoticeReturned(group.AssessmentNoticeReturned());
//    groupmodel->setAssessmentNoticeSuppressed(group.AssessmentNoticeSuppressed());
//    if (group.ChangeDate().present()) {
//        QDate date;
//        date.setDate(group.ChangeDate().get().year()
//                     , group.ChangeDate().get().month()
//                     , group.ChangeDate().get().day());
//        groupmodel->setChangeDate(date);
//    }
//    if (group.ChangeSource().present())
//        groupmodel->setChangeSource(QString::fromStdString(group.ChangeSource().get()));
//    if (group.ChangeSourceDescription().present())
//        groupmodel->setChangeSourceDescription(QString::fromStdString(group.ChangeSourceDescription().get()));
//    if (group.ChangeType().present())
//        groupmodel->setChangeType(QString::fromStdString(group.ChangeType().get()));
//    if (group.ChangeTypeDescription().present())
//        groupmodel->setChangeTypeDescription(QString::fromStdString(group.ChangeTypeDescription().get()));

//    return groupmodel;
//}
