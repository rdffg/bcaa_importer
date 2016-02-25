#include "mailingaddressconverter.h"

model::MailingAddress *converter::MailingAddressConverter::convert(
        dataadvice::MailingAddress const &addr) {
    auto addrmodel = new model::MailingAddress();
    if (addr.Attention().present())
        addrmodel->setAttention(QString::fromStdString(addr.Attention().get()));
    if (addr.BulkMailCode().present())
        addrmodel->setBulkMailCode(QString::fromStdString(addr.BulkMailCode().get()));
    if (addr.CareOf().present())
        addrmodel->setCareOf(QString::fromStdString(addr.CareOf().get()));
    if (addr.City().present())
        addrmodel->setCity(QString::fromStdString(addr.City().get()));
    if (addr.Compartment().present())
        addrmodel->setCompartment(QString::fromStdString(addr.Compartment().get()));
    if (addr.Country().present())
        addrmodel->setCountry(QString::fromStdString(addr.Country().get()));
    if (addr.DeliveryInstallationType().present())
        addrmodel->setDeliveryInstallationType(QString::fromStdString(addr.DeliveryInstallationType().get()));
    if (addr.Floor().present())
        addrmodel->setFloor(QString::fromStdString(addr.Floor().get()));
    if (addr.FreeformAddress().present())
        addrmodel->setFreeFormAddress(QString::fromStdString(addr.FreeformAddress().get()));
    if (addr.ModeOfDelivery().present())
        addrmodel->setModeOfDelivery(QString::fromStdString(addr.ModeOfDelivery().get()));
    if (addr.PostalZip().present())
        addrmodel->setPostalZip(QString::fromStdString(addr.PostalZip().get()));
    if (addr.ProvinceState().present())
        addrmodel->setProvinceState(QString::fromStdString(addr.ProvinceState().get()));
    if (addr.Site().present())
        addrmodel->setSite(QString::fromStdString(addr.Site().get()));
    if (addr.StreetDirectionPrefix().present())
        addrmodel->setStreetDirectionPrefix(QString::fromStdString(addr.StreetDirectionPrefix().get()));
    if (addr.StreetDirectionSuffix().present())
        addrmodel->setStreetDirectionSuffix(QString::fromStdString(addr.StreetDirectionSuffix().get()));
    if (addr.StreetName().present())
        addrmodel->setStreetName(QString::fromStdString(addr.StreetName().get()));
    if (addr.StreetType().present())
        addrmodel->setStreetType(QString::fromStdString(addr.StreetType().get()));
    if (addr.UnitNumber().present())
        addrmodel->setUnitNumber(QString::fromStdString(addr.UnitNumber().get()));
    return addrmodel;
}
