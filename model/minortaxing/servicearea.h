#ifndef SERVICEAREA_H
#define SERVICEAREA_H
#include "minortaxing.h"

namespace model
{ namespace minortaxing {
class ServiceArea : public MinorTaxing
{
    Q_OBJECT
    Q_CLASSINFO("__meta__", "db_table=service_area")
public:
    explicit ServiceArea(QObject *parent=0);
};
} }
#endif // SERVICEAREA_H
