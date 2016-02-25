#ifndef FORMATTEDMAILINGADDRESSCONVERTER_H
#define FORMATTEDMAILINGADDRESSCONVERTER_H
#include <memory>
#include "DataAdvice.hxx"
#include "model/formattedmailingaddress.h"

namespace converter {
class FormattedMailingAddressConverter
{
public:
    static model::FormattedMailingAddress* convert(dataadvice::FormattedMailingAddress const &addr);
};
}

#endif // FORMATTEDMAILINGADDRESSCONVERTER_H
