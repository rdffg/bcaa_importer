#include "managedforest.h"

namespace model {

ManagedForest::ManagedForest(QObject *parent) : QDjangoModel(parent)
{

}

QString ManagedForest::managedForestNumber() const
{
    return m_managedForestNumber;
}

void ManagedForest::setManagedForestNumber(const QString &managedForestNumber)
{
    m_managedForestNumber = managedForestNumber;
}

Folio *ManagedForest::folio() const
{
    return qobject_cast<model::Folio *>(foreignKey("folio"));
}

void ManagedForest::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

//std::unique_ptr<ManagedForest> ManagedForest::fromXml(const dataadvice::ManagedForest &forest)
//{
//    auto model = std::make_unique<ManagedForest>();
//    if (forest.ManagedForestNumber().present())
//        model->setManagedForestNumber(QString::fromStdString(forest.ManagedForestNumber().get()));
//    return model;
//}

} // namespace model
