#ifndef ELECTORALAREA_H
#define ELECTORALAREA_H
#include "minortaxing.h"

namespace model {
namespace minortaxing {
class ElectoralArea : public model::minortaxing::MinorTaxing
{
    Q_OBJECT
    Q_CLASSINFO("__meta__", "db_table=electoral_area")
public:
    explicit ElectoralArea(QObject *parent=0);
};
}
}
#endif // ELECTORALAREA_H
