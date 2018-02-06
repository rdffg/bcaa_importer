#ifndef OWNERGROUP_H
#define OWNERGROUP_H

#include <QDate>
#include "QDjangoModel.h"
#include "model/folio.h"
#include "model/owner.h"
#include "model/formattedmailingaddress.h"

#define FOLIO_PROPERTY "folio"
#define MAILING_ADDRESS_PROPERTY "mailingAddress"
#define FORMATTED_MAILING_ADDRESS_PROPERTY "formattedMailingAddress"

namespace model {
class Owner;
class FormattedMailingAddress;
class MailingAddress;

class OwnershipGroup : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(bool assessmentNoticeReturned READ assessmentNoticeReturned WRITE setAssessmentNoticeReturned)
    Q_PROPERTY(bool assessmentNoticeSuppressed READ assessmentNoticeSuppressed WRITE setAssessmentNoticeSuppressed)
    Q_PROPERTY(QString changeType READ changeType WRITE setChangeType)
    Q_PROPERTY(QString changeTypeDescription READ changeTypeDescription WRITE setChangeTypeDescription)
    Q_PROPERTY(QDate changeDate READ changeDate WRITE setChangeDate)
    Q_PROPERTY(QString changeSource READ changeSource WRITE setChangeSource)
    Q_PROPERTY(QString changeSourceDescription READ changeSourceDescription WRITE setChangeSourceDescription)
    Q_PROPERTY(model::Folio * folio READ folio WRITE setFolio)
    Q_PROPERTY(model::MailingAddress* mailingAddress READ mailingAddress WRITE setMailingAddress)
    Q_PROPERTY(model::FormattedMailingAddress* formattedMailingAddress READ formattedMailingAddress WRITE setFormattedMailingAddress)

    Q_CLASSINFO("__meta__", "db_table=ownership_group")
    Q_CLASSINFO("assessmentNoticeReturned", "null=true")
    Q_CLASSINFO("assessmentNoticeSuppressed", "null=true")
    Q_CLASSINFO("changeType", "null=true")
    Q_CLASSINFO("changeTypeDescription", "null=true")
    Q_CLASSINFO("changeDate", "null=true")
    Q_CLASSINFO("changeSource", "null=true")
    Q_CLASSINFO("changeSourceDescription", "null=true")
    Q_CLASSINFO(MAILING_ADDRESS_PROPERTY, "db_column=mailing_address_id null=true")
    Q_CLASSINFO(FORMATTED_MAILING_ADDRESS_PROPERTY, "db_column=formatted_mailing_address_id null=true")
    Q_CLASSINFO(FOLIO_PROPERTY, "on_delete=cascade")
public:
    explicit OwnershipGroup(QObject *parent = 0);

    bool assessmentNoticeReturned() const;
    void setAssessmentNoticeReturned(bool returned);
    bool assessmentNoticeSuppressed() const;
    void setAssessmentNoticeSuppressed(bool suppressed);
    QString changeType() const;
    void setChangeType(QString changeType);
    QString changeTypeDescription() const;
    void setChangeTypeDescription(QString descr);
    QDate changeDate() const;
    void setChangeDate(QDate date);
    QString changeSource() const;
    void setChangeSource(QString source);
    QString changeSourceDescription() const;
    void setChangeSourceDescription(QString descr);
    Folio *folio() const;
    void setFolio(Folio *folio);
    std::vector<std::unique_ptr<model::Owner>>& owners();
    void setOwners(std::vector<std::unique_ptr<model::Owner>> &owners);
    model::FormattedMailingAddress* formattedMailingAddress();
    void setFormattedMailingAddress(model::FormattedMailingAddress* addresses);
    void setFormattedMailingAddress(std::unique_ptr<model::FormattedMailingAddress> addresses);
    model::MailingAddress* mailingAddress();
    void setMailingAddress(model::MailingAddress*);
    void setMailingAddress(std::unique_ptr<model::MailingAddress> mailingAddress);

signals:

public slots:

private:
    bool m_assessmentNoticeReturned;
    bool m_assessmentNoticeSuppressed;
    QString m_changeType;
    QString m_changeTypeDescription;
    QDate m_changeDate;
    QString m_changeSource;
    QString m_changeSourceDescription;
    std::vector<std::unique_ptr<model::Owner> > m_owners;
    std::unique_ptr<model::FormattedMailingAddress> m_address;
    std::unique_ptr<model::MailingAddress> m_mailingAddress;
};
}

#endif // OWNERGROUP_H
