#ifndef OWNERCONVERTER_H
#define OWNERCONVERTER_H

#include "DataAdvice.hxx"
#include "model/owner.h"

namespace converter {
class OwnerConverter
{
public:
    Owner *convert(const dataadvice::Owner &xowner);
};
}
#endif // OWNERCONVERTER_H
