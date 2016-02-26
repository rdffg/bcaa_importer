#ifndef MINORTAXING_H
#define MINORTAXING_H

#include "QDjangoModel.h"
#include "minortaxingjurisdiction.h"
#include "model/minortaxing/minortaxingjurisdiction.h"
#include "../folio.h"

namespace model {
namespace minortaxing {
/**
 * @brief The MinorTaxing class
 *
 * Don't register this class with the QDjango framework. It doesn't get a table
 * in the database, and exists only to be inherited by other models.
 */
class MinorTaxing : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)
    Q_PROPERTY(model::minortaxing::MinorTaxingJurisdiction *minorTaxingJurisdiction READ minorTaxingJurisdiction WRITE setMinorTaxingJurisdiction)

    Q_CLASSINFO("folio", "null=true")
    Q_CLASSINFO("minorTaxingJurisdiction", "null=true")

public:
        explicit MinorTaxing(QObject *parent=0);

        model::Folio *folio() const;
        void setFolio(model::Folio *folio);

        MinorTaxingJurisdiction *minorTaxingJurisdiction() const;
        void setMinorTaxingJurisdiction(MinorTaxingJurisdiction *jurisdiction);
};
}
}
#endif // MINORTAXING_H
