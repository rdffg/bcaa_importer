#include "ownergroup.h"
#include "mailingaddress.h"

using namespace model;
OwnershipGroup::OwnershipGroup(QObject *parent) : QDjangoModel(parent)
    , m_owners(std::vector<std::unique_ptr<model::Owner>>())
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

void OwnershipGroup::setOwners(std::vector<std::unique_ptr<Owner> >& owners)
{
    m_owners = std::move(owners);
}

model::FormattedMailingAddress* OwnershipGroup::formattedMailingAddress()
{
    return qobject_cast<model::FormattedMailingAddress *>(
                            foreignKey(FORMATTED_MAILING_ADDRESS_PROPERTY));
}

void OwnershipGroup::setFormattedMailingAddress(FormattedMailingAddress *addresses)
{
    if (m_ownershipGroupId != nullptr)
    {
        addresses->setId(m_ownershipGroupId);
    }
    setForeignKey(FORMATTED_MAILING_ADDRESS_PROPERTY, addresses);
}

void OwnershipGroup::setFormattedMailingAddress(std::unique_ptr<model::FormattedMailingAddress> address)
{
    m_address = std::move(address);
    setFormattedMailingAddress(m_address.get());
}

void OwnershipGroup::setMailingAddress(MailingAddress *addr)
{
    if (m_ownershipGroupId != nullptr)
    {
        addr->setId(m_ownershipGroupId);
    }
    setForeignKey(MAILING_ADDRESS_PROPERTY, addr);
}

model::MailingAddress* OwnershipGroup::mailingAddress()
{
    return qobject_cast<model::MailingAddress*>(foreignKey(MAILING_ADDRESS_PROPERTY));
}

void OwnershipGroup::setMailingAddress(std::unique_ptr<model::MailingAddress> mailingAddress)
{
    m_mailingAddress = std::move(mailingAddress);
    setMailingAddress(m_mailingAddress.get());
}

void OwnershipGroup::setOwnershipGroupId(QString id)
{
    if (formattedMailingAddress() != nullptr)
    {
        formattedMailingAddress()->setId(id);
    }
    if (mailingAddress() != nullptr)
    {
        mailingAddress()->setId(id);
    }
    m_ownershipGroupId = id;
}

QString OwnershipGroup::ownershipGroupId() const
{
    return m_ownershipGroupId;
}
