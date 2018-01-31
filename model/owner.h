#ifndef OWNER_H
#define OWNER_H

#include <memory>
#include "QDjangoModel.h"

#define OWNERSHIPGROUP_PROPERTY "ownershipGroup"

namespace model {
class OwnershipGroup;
class Owner : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname)
    Q_PROPERTY(QString middleName READ middleName WRITE setMiddleName)
    Q_PROPERTY(QString middleInitial READ middleInitial WRITE setMiddleInitial)
    Q_PROPERTY(QString companyOrLastName READ companyOrLastName WRITE setCompanyOrLastName)
    Q_PROPERTY(QString equityType READ equityType WRITE setEquityType)
    Q_PROPERTY(QString equityTypeDescription READ equityTypeDescription WRITE setEquityTypeDescription)
    Q_PROPERTY(QString ownerSequenceID READ ownerSequenceID WRITE setOwnerSequenceID)
    Q_PROPERTY(QString bca_id READ bca_id WRITE setId)
    Q_PROPERTY(model::OwnershipGroup* ownershipGroup READ ownershipGroup WRITE setOwnershipGroup)

    Q_CLASSINFO("__meta__", "db_table=owner")
    Q_CLASSINFO("firstname", "null=true")
    Q_CLASSINFO("middleName", "null=true")
    Q_CLASSINFO("middleInitial", "null=true")
    Q_CLASSINFO("companyOrLastName","null=true")
    Q_CLASSINFO("equityType", "null=true")
    Q_CLASSINFO("equityTypeDescription", "null=true")
    Q_CLASSINFO("ownerSequenceID", "null=true max_length=32")
    Q_CLASSINFO("id", "primary_key=true max_length=32")
    Q_CLASSINFO(OWNERSHIPGROUP_PROPERTY, "on_delete=cascade")

public:
    Owner(QObject *parent=0);

    QString firstname() const;
    void setFirstname(const QString &firstname);

    QString middleName() const;
    void setMiddleName(const QString &middleName);

    QString middleInitial() const;
    void setMiddleInitial(const QString &middleInitial);

    QString companyOrLastName() const;
    void setCompanyOrLastName(const QString &companyOrLastName);

    QString equityType() const;
    void setEquityType(const QString &equityType);

    QString equityTypeDescription() const;
    void setEquityTypeDescription(const QString &equityTypeDescription);

    OwnershipGroup *ownershipGroup() const;
    void setOwnershipGroup(OwnershipGroup *ownershipGroup);

    QString ownerSequenceID() const;
    void setOwnerSequenceID(const QString &ownerSequenceID);

    QString bca_id() const;
    void setId(const QString &bca_id);

private:
    QString m_id;
    QString m_firstname;
    QString m_middleName;
    QString m_middleInitial;
    QString m_companyOrLastName;
    QString m_equityType;
    QString m_equityTypeDescription;
    QString m_ownerSequenceID;
};
}
#endif // OWNER_H
