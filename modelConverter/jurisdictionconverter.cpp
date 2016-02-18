#include "jurisdictionconverter.h"

using namespace converter;
Jurisdiction *JurisdictionConverter::convert(dataadvice::Jurisdiction &jurisdiction)
{
    auto jurisdictionmodel = new Jurisdiction();
    jurisdictionmodel->setCode(QString::fromStdString(jurisdiction.JurisdictionCode()));
    if (jurisdiction.JurisdictionDescription().present())
        jurisdictionmodel->setDescription(
                    QString::fromStdString(jurisdiction.JurisdictionDescription().get()));
    return jurisdictionmodel;
}
