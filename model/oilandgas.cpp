#include "oilandgas.h"

namespace model {

OilAndGas::OilAndGas(QObject *parent) : QDjangoModel(parent)
{

}

QString OilAndGas::pipelineProjectNumber() const
{
    return m_pipelineProjectNumber;
}

void OilAndGas::setPipelineProjectNumber(const QString &pipelineProjectNumber)
{
    m_pipelineProjectNumber = pipelineProjectNumber;
}

Folio *OilAndGas::folio() const
{
    return qobject_cast<Folio *>(foreignKey("folio"));
}

void OilAndGas::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

void OilAndGas::setFolio(std::unique_ptr<Folio> folio)
{
    setForeignKey("folio", folio.get());
}

std::unique_ptr<OilAndGas> OilAndGas::fromXml(const dataadvice::OilAndGas &oil)
{
    auto model = std::make_unique<OilAndGas>();
    if (oil.PipelineProjectNumber().present())
        model->setPipelineProjectNumber(QString::fromStdString(oil.PipelineProjectNumber().get()));
    return model;
}

} // namespace model
