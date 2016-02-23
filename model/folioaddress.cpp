#include "folioaddress.h"

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

