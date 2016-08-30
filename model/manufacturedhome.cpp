#include "manufacturedhome.h"

using namespace model;
ManufacturedHome::ManufacturedHome(QObject *parent) : QDjangoModel(parent)
{

}

QString ManufacturedHome::mhRegistryNumber() const
{
    return m_mhRegistryNumber;
}

void ManufacturedHome::setMhRegistryNumber(const QString &mhRegistryNumber)
{
    m_mhRegistryNumber = mhRegistryNumber;
}

QString ManufacturedHome::mhBayNumber() const
{
    return m_mhBayNumber;
}

void ManufacturedHome::setMhBayNumber(const QString &mhBayNumber)
{
    m_mhBayNumber = mhBayNumber;
}

QString ManufacturedHome::mhPark() const
{
    return m_mhPark;
}

void ManufacturedHome::setMhPark(const QString &mhPark)
{
    m_mhPark = mhPark;
}

QString ManufacturedHome::mhParkRollNumber() const
{
    return m_mhParkRollNumber;
}

void ManufacturedHome::setMhParkRollNumber(const QString &mhParkRollNumber)
{
    m_mhParkRollNumber = mhParkRollNumber;
}

Folio *ManufacturedHome::folio() const
{
    return qobject_cast<model::Folio *>(foreignKey("folio"));
}

void ManufacturedHome::setFolio(model::Folio *folio)
{
    setForeignKey("folio", folio);
}

void ManufacturedHome::setFolio(std::unique_ptr<model::Folio> folio)
{
    setForeignKey("folio", folio.get());
}

QString ManufacturedHome::id() const
{
    return m_id;
}

void ManufacturedHome::setId(const QString &id)
{
    m_id = id;
}
