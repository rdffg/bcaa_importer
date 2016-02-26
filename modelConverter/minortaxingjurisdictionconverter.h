#ifndef MINORTAXINGJURISDICTIONCONVERTER_H
#define MINORTAXINGJURISDICTIONCONVERTER_H
#include "model/minortaxing/minortaxingjurisdiction.h"
#include "DataAdvice.hxx"

namespace converter {
class MinorTaxingJurisdictionConverter
{
public:
    static model::minortaxing::MinorTaxingJurisdiction *convert(const dataadvice::MinorTaxingJurisdiction &taxing);
};
}
#endif // MINORTAXINGJURISDICTIONCONVERTER_H
