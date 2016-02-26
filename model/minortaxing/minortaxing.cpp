#include "minortaxing.h"

using namespace model::minortaxing;
MinorTaxing::MinorTaxing(QObject *parent): QDjangoModel(parent)
{

}

model::Folio *MinorTaxing::folio() const
{
    return qobject_cast<model::Folio*>(foreignKey("folio"));
}

void MinorTaxing::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

MinorTaxingJurisdiction *MinorTaxing::minorTaxingJurisdiction() const
{
    return qobject_cast<MinorTaxingJurisdiction*>(foreignKey("minorTaxingJurisdiction"));
}

void MinorTaxing::setMinorTaxingJurisdiction(MinorTaxingJurisdiction *jurisdiction)
{
    setForeignKey("minorTaxingJurisdiction", jurisdiction);
}
