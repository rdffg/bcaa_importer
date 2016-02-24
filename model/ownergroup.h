#ifndef OWNERGROUP_H
#define OWNERGROUP_H

#include <QDate>
#include "QDjangoModel.h"
#include "model/folio.h"

#define FOLIO_PROPERTY "folio"

namespace model {
class OwnershipGroup : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString tenureCode READ tenureCode WRITE setTenureCode)
    Q_PROPERTY(QString tenureDescription READ tenureDescription WRITE setTenureDescription)
    Q_PROPERTY(bool assessmentNoticeReturned READ assessmentNoticeReturned WRITE setAssessmentNoticeReturned)
    Q_PROPERTY(bool assessmentNoticeSuppressed READ assessmentNoticeSuppressed WRITE setAssessmentNoticeSuppressed)
    Q_PROPERTY(QString changeType READ changeType WRITE setChangeType)
    Q_PROPERTY(QString changeTypeDescription READ changeTypeDescription WRITE setChangeTypeDescription)
    Q_PROPERTY(QDate changeDate READ changeDate WRITE setChangeDate)
    Q_PROPERTY(QString changeSource READ changeSource WRITE setChangeSource)
    Q_PROPERTY(QString changeSourceDescription READ changeSourceDescription WRITE setChangeSourceDescription)
    Q_PROPERTY(Folio * folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=ownership_group")
    Q_CLASSINFO("tenureCode", "null=true")
    Q_CLASSINFO("tenureDescription", "null=true")
    Q_CLASSINFO("assessmentNoticeReturned", "null=true")
    Q_CLASSINFO("assessmentNoticeSuppressed", "null=true")
    Q_CLASSINFO("changeType", "null=true")
    Q_CLASSINFO("changeTypeDescription", "null=true")
    Q_CLASSINFO("changeDate", "null=true")
    Q_CLASSINFO("changeSource", "null=true")
    Q_CLASSINFO("changeSourceDescription", "null=true")
    Q_CLASSINFO(FOLIO_PROPERTY, "on_delete=cascade")
public:
    explicit OwnershipGroup(QObject *parent = 0);

    QString tenureCode() const;
    void setTenureCode(const QString &value);
    QString tenureDescription() const;
    void setTenureDescription(const QString &value);
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

signals:

public slots:

private:
    QString m_tenureCode;
    QString m_tenureDescription;
    bool m_assessmentNoticeReturned;
    bool m_assessmentNoticeSuppressed;
    QString m_changeType;
    QString m_changeTypeDescription;
    QDate m_changeDate;
    QString m_changeSource;
    QString m_changeSourceDescription;
};
}

#endif // OWNERGROUP_H
