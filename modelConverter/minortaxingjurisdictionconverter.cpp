#include "minortaxingjurisdictionconverter.h"

using namespace converter;
model::minortaxing::MinorTaxingJurisdiction *MinorTaxingJurisdictionConverter::convert(const dataadvice::MinorTaxingJurisdiction &taxing)
{
    model::minortaxing::MinorTaxingJurisdiction* mtaxing = new model::minortaxing::MinorTaxingJurisdiction();
    if (taxing.MinorTaxingCode().present())
        mtaxing->setCode(QString::fromStdString(taxing.MinorTaxingCode().get()));
    if (taxing.MinorTaxingCodeShort().present())
        mtaxing->setShortCode(QString::fromStdString(taxing.MinorTaxingCodeShort().get()));
    if (taxing.MinorTaxingDescription().present())
        mtaxing->setMinorTaxingDescription(QString::fromStdString(taxing.MinorTaxingDescription().get()));
    return mtaxing;
}
