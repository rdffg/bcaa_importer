#include "formattedmailingaddressconverter.h"

using namespace converter;
model::FormattedMailingAddress* FormattedMailingAddressConverter::convert(const dataadvice::FormattedMailingAddress &addr)
{
    auto addrmodel = new model::FormattedMailingAddress();
    if (addr.Line1().present())
        addrmodel->setLine1(QString::fromStdString(addr.Line1().get()));
    if (addr.Line2().present())
        addrmodel->setLine2(QString::fromStdString(addr.Line2().get()));
    if (addr.Line3().present())
        addrmodel->setLine3(QString::fromStdString(addr.Line3().get()));
    if (addr.Line4().present())
        addrmodel->setLine4(QString::fromStdString(addr.Line4().get()));
    if (addr.Line5().present())
        addrmodel->setLine5(QString::fromStdString(addr.Line5().get()));
    if (addr.Line6().present())
        addrmodel->setLine6(QString::fromStdString(addr.Line6().get()));
    return addrmodel;
}
