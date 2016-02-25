#include "folioaddressconverter.h"


using namespace converter;
model::FolioAddress *FolioAddressConverter::convert(dataadvice::FolioAddress &xml_model)
{
   model::FolioAddress *addr = new model::FolioAddress();
   if (xml_model.UnitNumber().present())
           addr->setUnitNumber(QString::fromStdString(xml_model.UnitNumber().get()));
   if (xml_model.StreetDirectionPrefix().present())
           addr->setStreetDirectionPrefix(QString::fromStdString(xml_model.StreetDirectionPrefix().get()));
   if (xml_model.StreetName().present())
           addr->setStreetName(QString::fromStdString(xml_model.StreetName().get()));
   if (xml_model.StreetType().present())
           addr->setStreetType(QString::fromStdString(xml_model.StreetType().get()));
   if (xml_model.StreetDirectionSuffix().present())
           addr->setStreetDirectionSuffix(QString::fromStdString(xml_model.StreetDirectionSuffix().get()));
   if (xml_model.City().present())
       addr->setCity(QString::fromStdString(xml_model.City().get()));
   if (xml_model.StreetNumber().present())
       addr->setStreetNumber(QString::fromStdString(xml_model.StreetNumber().get()));
   if (xml_model.MapReferenceNumber().present())
       addr->setMapReferenceNumber(QString::fromStdString(xml_model.MapReferenceNumber().get()));
   if (xml_model.PostalZip().present())
       addr->setPostalCode(QString::fromStdString(xml_model.PostalZip().get()));
   return addr;
}
