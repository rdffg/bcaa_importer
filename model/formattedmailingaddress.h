#ifndef FORMATTEDMAILINGADDRESS_H
#define FORMATTEDMAILINGADDRESS_H
#include "model/ownergroup.h"
#include "QDjangoModel.h"

namespace model {
class FormattedMailingAddress : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString line1 READ line1 WRITE setLine1)
    Q_PROPERTY(QString line2 READ line2 WRITE setLine2)
    Q_PROPERTY(QString line3 READ line3 WRITE setLine3)
    Q_PROPERTY(QString line4 READ line4 WRITE setLine4)
    Q_PROPERTY(QString line5 READ line5 WRITE setLine5)
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString line6 READ line6 WRITE setLine6)

    Q_CLASSINFO("__meta__", "db_table=formatted_mailing_address")
    Q_CLASSINFO("id", "primary_key=true max_length=32")
    Q_CLASSINFO("line1", "null=true length=40")
    Q_CLASSINFO("line2", "null=true length=40")
    Q_CLASSINFO("line3", "null=true length=40")
    Q_CLASSINFO("line4", "null=true length=40")
    Q_CLASSINFO("line5", "null=true length=40")
    Q_CLASSINFO("line6", "null=true length=40")

public:
    explicit FormattedMailingAddress(QObject *parent=0);
    QString line1() const;
    void setLine1(const QString &line1);

    QString line2() const;
    void setLine2(const QString &line2);

    QString line3() const;
    void setLine3(const QString &line3);

    QString line4() const;
    void setLine4(const QString &line4);

    QString line5() const;
    void setLine5(const QString &line5);

    QString line6() const;
    void setLine6(const QString &line6);

    QString id() const;
    void setId(const QString &id);

private:
    QString m_id;
    QString m_line1;
    QString m_line2;
    QString m_line3;
    QString m_line4;
    QString m_line5;
    QString m_line6;
};
}

#endif // FORMATTEDMAILINGADDRESS_H
