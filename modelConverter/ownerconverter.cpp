#include "ownerconverter.h"

using namespace converter;
model::Owner *OwnerConverter::convert(const dataadvice::Owner &xowner) {
    auto owner = new model::Owner();
    owner->setCompanyOrLastName(QString::fromStdString(xowner.CompanyOrLastName()));
    if (xowner.FirstName().present())
        owner->setFirstname(QString::fromStdString(xowner.FirstName().get()));
    if (xowner.MiddleInitial().present())
        owner->setMiddleInitial(QString::fromStdString(xowner.MiddleInitial().get()));
    if (xowner.MiddleName().present())
        owner->setMiddleName(QString::fromStdString(xowner.MiddleName().get()));
    if (xowner.EquityType().present())
        owner->setEquityType(QString::fromStdString(xowner.EquityType().get()));
    if (xowner.EquityTypeDescription().present())
        owner->setEquityTypeDescription(QString::fromStdString(xowner.EquityTypeDescription().get()));
    return owner;
}
