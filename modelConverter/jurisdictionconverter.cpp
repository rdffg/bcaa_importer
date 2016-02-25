#include "jurisdictionconverter.h"

using namespace converter;
model::Jurisdiction *JurisdictionConverter::convert(dataadvice::Jurisdiction &jurisdiction)
{
    auto jurisdictionmodel = new model::Jurisdiction();
    jurisdictionmodel->setCode(QString::fromStdString(jurisdiction.JurisdictionCode()));
    if (jurisdiction.JurisdictionDescription().present())
        jurisdictionmodel->setDescription(
                    QString::fromStdString(jurisdiction.JurisdictionDescription().get()));
    return jurisdictionmodel;
}
