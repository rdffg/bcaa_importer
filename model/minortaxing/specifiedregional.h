#ifndef SPECIFIEDREGIONAL_H
#define SPECIFIEDREGIONAL_H
#include "minortaxing.h"

namespace model {
namespace minortaxing {
class SpecifiedRegional: public MinorTaxing
{
    Q_OBJECT
    Q_CLASSINFO("__meta__","db_name=specified_regional")
public:
    explicit SpecifiedRegional(QObject *parent=0);
};
}
}
#endif // SPECIFIEDREGIONAL_H
