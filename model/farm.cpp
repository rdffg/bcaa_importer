#include "farm.h"
#include <QUuid>

namespace model {

Farm::Farm(QObject *parent) : QDjangoModel(parent)
{

}

QString Farm::farmNumber() const
{
    return m_farmNumber;
}

void Farm::setFarmNumber(const QString &farmNumber)
{
    m_farmNumber = farmNumber;
}

Folio *Farm::folio() const
{
    return qobject_cast<Folio *>(foreignKey("folio"));
}

void Farm::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

void Farm::setFolio(std::unique_ptr<Folio> folio)
{
    setForeignKey("folio", folio.get());
}

QString Farm::id() const
{
    return m_id;
}

#pragma warning( push )
#pragma warning( disable: 4100)
void Farm::setId(const QString /* &id */)
#pragma warning( pop )
{
    // hackety hack hack...
    // replace the farm ID with a GUID, because the xml advice
    // doc uses the farm number as the ID, but it's not unique to the
    // folio-farm combo. Really *should* rebuild this as a many-to-many,
    // but this is expedient.
    //m_id = id;
    auto uuid = QUuid::createUuid();
    m_id = uuid.toString(QUuid::StringFormat::Id128);
}

} // namespace model
