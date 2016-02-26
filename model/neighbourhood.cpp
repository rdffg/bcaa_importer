#include "neighbourhood.h"

using namespace model;
Neighbourhood::Neighbourhood(QObject *parent): QDjangoModel (parent)
{

}

QString Neighbourhood::neighbourhoodCode() const
{
    return m_neighbourhoodCode;
}

void Neighbourhood::setNeighbourhoodCode(const QString &neighbourhoodCode)
{
    m_neighbourhoodCode = neighbourhoodCode;
}

QString Neighbourhood::neighbourhoodDescription() const
{
    return m_neighbourhoodDescription;
}

void Neighbourhood::setNeighbourhoodDescription(const QString &neighbourhoodDescription)
{
    m_neighbourhoodDescription = neighbourhoodDescription;
}

FolioDescription *Neighbourhood::folioDescription() const
{
    return qobject_cast<model::FolioDescription*>(foreignKey(NEIGHBOURHOOD_FOLIODESCRIPTION_PROPERTY));
}

void Neighbourhood::setFolioDescription(FolioDescription *descr)
{
    setForeignKey(NEIGHBOURHOOD_FOLIODESCRIPTION_PROPERTY, descr);
}
