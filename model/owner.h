#ifndef OWNER_H
#define OWNER_H

#include <memory>
#include "QDjangoModel.h"
#include "ownergroup.h"

#define OWNERSHIPGROUP_PROPERTY "ownershipGroup"

class Owner : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname)
    Q_PROPERTY(QString middleName READ middleName WRITE setMiddleName)
    Q_PROPERTY(QString middelInitial READ middleInitial WRITE setMiddleInitial)
    Q_PROPERTY(QString companyOrLastName READ companyOrLastName WRITE setCompanyOrLastName)
    Q_PROPERTY(QString equityType READ equityType WRITE setEquityType)
    Q_PROPERTY(QString equityTypeDescription READ equityTypeDescription WRITE setEquityTypeDescription)
    Q_PROPERTY(OwnershipGroup* ownershipGroup READ ownershipGroup WRITE setOwnershipGroup)

    Q_CLASSINFO("firstname", "null=true")
    Q_CLASSINFO("middleName", "null=true")
    Q_CLASSINFO("middleInitial", "null=true")
    Q_CLASSINFO("companyOrLastName","null=true")
    Q_CLASSINFO("equityType", "null=true")
    Q_CLASSINFO("equityTypeDescription", "null=true")
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

private:
    QString m_firstname;
    QString m_middleName;
    QString m_middleInitial;
    QString m_companyOrLastName;
    QString m_equityType;
    QString m_equityTypeDescription;
};

#endif // OWNER_H
