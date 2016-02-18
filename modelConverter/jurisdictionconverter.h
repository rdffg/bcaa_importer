#ifndef JURISDICTIONCONVERTER_H
#define JURISDICTIONCONVERTER_H
#include "model/jurisdiction.h"
#include "DataAdvice.hxx"

namespace converter {

class JurisdictionConverter
{
public:
    static Jurisdiction *convert(dataadvice::Jurisdiction &jurisdiction);
};
}

#endif // JURISDICTIONCONVERTER_H
