#ifndef OWNERSHIPGROUPCONVERTER_H
#define OWNERSHIPGROUPCONVERTER_H

#include "DataAdvice.hxx"
#include "model/ownergroup.h"

namespace converter {
class OwnershipGroupConverter
{
public:
    static model::OwnershipGroup* convert(const dataadvice::OwnershipGroup &group);
};
}
#endif // OWNERSHIPGROUPCONVERTER_H
