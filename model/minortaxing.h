#ifndef MINORTAXING_H
#define MINORTAXING_H
#include "QDjangoModel.h"

namespace model {
class MinorTaxing : public QDjangoModel
{
public:
    explicit MinorTaxing(QObject *parent=0);
};
}

#endif // MINORTAXING_H
