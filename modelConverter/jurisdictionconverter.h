#ifndef JURISDICTIONCONVERTER_H
#define JURISDICTIONCONVERTER_H
#include "model/jurisdiction.h"
#include "DataAdvice.hxx"

namespace converter {

class JurisdictionConverter
{
public:
    static model::Jurisdiction *convert(dataadvice::Jurisdiction &jurisdiction);
};
}

#endif // JURISDICTIONCONVERTER_H
