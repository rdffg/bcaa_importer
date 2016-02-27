#ifndef DEFINED_H
#define DEFINED_H

#include "minortaxing.h"

namespace model {
namespace minortaxing {
class Defined : public MinorTaxing
{
        Q_OBJECT
        Q_CLASSINFO("__meta__","db_table=defined")
public:
    explicit Defined(QObject *parent=0);
};
}
}
#endif // DEFINED_H
