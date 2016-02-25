#ifndef MAILINGADDRESSCONVERTER_H
#define MAILINGADDRESSCONVERTER_H

#include <memory>
#include "model/mailingaddress.h"
#include "DataAdvice.hxx"

namespace converter {
class MailingAddressConverter
{
public:
    static model::MailingAddress* convert(dataadvice::MailingAddress const &addr);
};
}

#endif // MAILINGADDRESSCONVERTER_H
