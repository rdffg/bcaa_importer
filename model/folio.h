#ifndef FOLIO_H
#define FOLIO_H

#include <QObject>
#include "QDjangoModel.h"
#include "jurisdiction.h"

#define JURISDICTION_PROPERTY "jurisdiction"

namespace model {
class Folio : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString rollNumber READ rollNumber WRITE setRollNumber)
    Q_PROPERTY(QString status READ status WRITE setStatus)
    Q_PROPERTY(QString statusDescription READ statusDescription WRITE setStatusDescription)
    Q_PROPERTY(model::Jurisdiction *jurisdiction READ jurisdiction WRITE setJurisdiction)

    Q_CLASSINFO("__meta__", "db_table=folio")
    Q_CLASSINFO("rollNumber", "max_length=32")
    Q_CLASSINFO("status", "max_length=16 blank=true null=true")
    Q_CLASSINFO("statusDescription", "max_length=255 blank=true null=true")
    Q_CLASSINFO(JURISDICTION_PROPERTY, "on_delete=cascade")

public:
    explicit Folio(QObject *parent=0);
    QString rollNumber();
    void setRollNumber(QString num);
    QString status();
    void setStatus(QString status);
    QString statusDescription();
    void setStatusDescription(QString desc);
    Jurisdiction *jurisdiction() const;
    void setJurisdiction(Jurisdiction *juris);

signals:

public slots:
private:
    QString m_rollNumber;
    QString m_status;
    QString m_statusDescription;
};
}
#endif // FOLIO_H
