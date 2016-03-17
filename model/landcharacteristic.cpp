#include "landcharacteristic.h"

namespace model {

LandCharacteristic::LandCharacteristic(QObject *parent) : QDjangoModel(parent)
{

}

QString LandCharacteristic::code() const
{
    return m_code;
}

void LandCharacteristic::setCode(const QString &code)
{
    m_code = code;
}

QString LandCharacteristic::description() const
{
    return m_description;
}

void LandCharacteristic::setDescription(const QString &description)
{
    m_description = description;
}

Folio *LandCharacteristic::folio() const
{
    return qobject_cast<Folio *>(foreignKey("folio"));
}

void LandCharacteristic::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

void LandCharacteristic::setFolio(std::unique_ptr<Folio> folio)
{
    setForeignKey("folio", folio.get());
}

std::unique_ptr<LandCharacteristic> LandCharacteristic::fromXml(const dataadvice::LandCharacteristic &characteristic)
{
    auto model = std::make_unique<LandCharacteristic>();
    if (characteristic.LandCharacteristicCode().present())
        model->setCode(QString::fromStdString(characteristic.LandCharacteristicCode().get()));
    if (characteristic.LandCharacteristicDescription().present())
        model->setDescription(QString::fromStdString(characteristic.LandCharacteristicDescription().get()));
    return model;
}

} // namespace model
