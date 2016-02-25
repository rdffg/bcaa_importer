#ifndef FOLIOADDRESSCONVERTER_H
#define FOLIOADDRESSCONVERTER_H
#include "model/folioaddress.h"
#include "DataAdvice.hxx"

namespace converter {
class FolioAddressConverter
{
public:
    static model::FolioAddress* convert(dataadvice::FolioAddress &xml_model);
};
}
#endif // FOLIOADDRESSCONVERTER_H
