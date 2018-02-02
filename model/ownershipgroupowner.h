#ifndef OWNERSHIPGROUPOWNER_H
#define OWNERSHIPGROUPOWNER_H

#include <QObject>
#include <QDjangoModel.h>
#include "model.h"

#define OWNERSHIPGROUP_PROPERTY "ownershipGroup"
#define OWNER_PROPERTY "owner"

namespace model {
class OwnershipGroupOwner : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(model::Owner* owner READ owner WRITE setOwner)
    Q_PROPERTY(model::OwnershipGroup* ownershipGroup READ ownershipGroup WRITE setOwnershipGroup)

    Q_CLASSINFO("__meta__", "db_table=ownership_group_owner")
    Q_CLASSINFO(OWNERSHIPGROUP_PROPERTY, "on_delete=cascade")
    Q_CLASSINFO(OWNER_PROPERTY, "on_delete=cascade")
public:
    explicit OwnershipGroupOwner(QObject *parent = nullptr);
    model::Owner* owner() const;
    void setOwner(model::Owner* owner);
    model::OwnershipGroup* ownershipGroup() const;
    void setOwnershipGroup(model::OwnershipGroup* ownershipGroup);

signals:

public slots:
};
};
#endif // OWNERSHIPGROUPOWNER_H
