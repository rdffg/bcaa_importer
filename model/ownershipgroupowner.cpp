#include "ownershipgroupowner.h"

using namespace model;

OwnershipGroupOwner::OwnershipGroupOwner(QObject *parent) : QDjangoModel(parent)
{

}

Owner* OwnershipGroupOwner::owner() const
{
    return qobject_cast<Owner*>(foreignKey(OWNER_PROPERTY));
}

void OwnershipGroupOwner::setOwner(Owner* owner)
{
    setForeignKey(OWNER_PROPERTY, owner);
}

OwnershipGroup* OwnershipGroupOwner::ownershipGroup() const
{
    return qobject_cast<OwnershipGroup*>(foreignKey(OWNERSHIPGROUP_PROPERTY));
}

void OwnershipGroupOwner::setOwnershipGroup(OwnershipGroup* ownershipGroup)
{
    setForeignKey(OWNERSHIPGROUP_PROPERTY, ownershipGroup);
}
