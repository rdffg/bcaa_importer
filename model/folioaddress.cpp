#include "folioaddress.h"

using namespace model;
FolioAddress::FolioAddress(QObject *parent) : QDjangoModel(parent)
  , m_primaryFlag(false)
  , m_unit(QString())
  , m_streetno(QString())
  , m_streetdirpre(QString())
  , m_streetname(QString())
  , m_streetdirsuff(QString())
  , m_city(QString())
  , m_postalcode(QString())
  , m_mapref(QString())
  , m_streettype(QString())
{
    //setForeignKey(FOLIO_PROPERTY, new Folio());
}

bool FolioAddress::primaryFlag() {
    return m_primaryFlag;
}

void FolioAddress::setPrimaryFlag(bool flag) {
    m_primaryFlag = flag;
}

QString FolioAddress::unitNumber() {
    return m_unit;
}

void FolioAddress::setUnitNumber(QString unit)
{
    m_unit = unit;
}

QString FolioAddress::streetNumber()
{
    return m_streetno;
}

void FolioAddress::setStreetNumber(QString streetnum)
{
    m_streetno = streetnum;
}

QString FolioAddress::streetDirectionPrefix()
{
    return m_streetdirpre;
}

void FolioAddress::setStreetDirectionPrefix(QString prefix)
{
    m_streetdirpre = prefix;
}

QString FolioAddress::streetName()
{
    return m_streetname;
}

void FolioAddress::setStreetName(QString name)
{
    m_streetname = name;
}

QString FolioAddress::streetType()
{
    return m_streettype;
}

void FolioAddress::setStreetType(QString type)
{
    m_streettype = type;
}

QString FolioAddress::streetDirectionSuffix()
{
    return m_streetdirsuff;
}

void FolioAddress::setStreetDirectionSuffix(QString suffix) {
    m_streetdirsuff = suffix;
}

QString FolioAddress::city()
{
    return m_city;
}

void FolioAddress::setCity(QString city)
{
    m_city = city;
}

QString FolioAddress::postalCode()
{
    return m_postalcode;
}

void FolioAddress::setPostalCode(QString code)
{
    m_postalcode = code;
}

QString FolioAddress::mapReferenceNumber()
{
    return m_mapref;
}

void FolioAddress::setMapReferenceNumber(QString mapref)
{
    m_mapref = mapref;
}

Folio *FolioAddress::folio() {
    return qobject_cast<Folio *>(foreignKey(FOLIO_PROPERTY));
}

void FolioAddress::setFolio(Folio *folio) {
    setForeignKey(FOLIO_PROPERTY, folio);
}

QString FolioAddress::provinceState() const
{
    return m_provinceState;
}

void FolioAddress::setProvinceState(const QString &provinceState)
{
    m_provinceState = provinceState;
}

QString FolioAddress::id() const
{
    return m_id;
}

void FolioAddress::setId(const QString &id)
{
    m_id = id;
}

//FolioAddress::FolioAddress(FolioAddress &&f)
//{

//}

//FolioAddress *FolioAddress::fromXml(dataadvice::FolioAddress const &xml_model)
//{
//   model::FolioAddress *addr = new model::FolioAddress();
//   if (xml_model.UnitNumber().present())
//           addr->setUnitNumber(QString::fromStdString(xml_model.UnitNumber().get()));
//   if (xml_model.StreetDirectionPrefix().present())
//           addr->setStreetDirectionPrefix(QString::fromStdString(xml_model.StreetDirectionPrefix().get()));
//   if (xml_model.StreetName().present())
//           addr->setStreetName(QString::fromStdString(xml_model.StreetName().get()));
//   if (xml_model.StreetType().present())
//           addr->setStreetType(QString::fromStdString(xml_model.StreetType().get()));
//   if (xml_model.StreetDirectionSuffix().present())
//           addr->setStreetDirectionSuffix(QString::fromStdString(xml_model.StreetDirectionSuffix().get()));
//   if (xml_model.City().present())
//       addr->setCity(QString::fromStdString(xml_model.City().get()));
//   if (xml_model.StreetNumber().present())
//       addr->setStreetNumber(QString::fromStdString(xml_model.StreetNumber().get()));
//   if (xml_model.MapReferenceNumber().present())
//       addr->setMapReferenceNumber(QString::fromStdString(xml_model.MapReferenceNumber().get()));
//   if (xml_model.PostalZip().present())
//       addr->setPostalCode(QString::fromStdString(xml_model.PostalZip().get()));
//   return addr;
//}

