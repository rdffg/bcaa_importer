#include "farm.h"

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

void Farm::setId(const QString &id)
{
    m_id = id;
}

//std::unique_ptr<Farm> Farm::fromXml(const dataadvice::FolioString255Item &farmNumber)
//{
//    auto model = std::make_unique<Farm>();
//    model->setFarmNumber(QString::fromStdString(farmNumber));
//    return model;
//}

} // namespace model
