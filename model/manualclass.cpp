#include "manualclass.h"

using namespace model;
ManualClass::ManualClass(QObject *parent): QDjangoModel(parent)
{

}

QString ManualClass::manualClassCode() const
{
    return m_manualClassCode;
}

void ManualClass::setManualClassCode(const QString &manualClassCode)
{
    m_manualClassCode = manualClassCode;
}

QString ManualClass::manualClassDescription() const
{
    return m_manualClassDescription;
}

void ManualClass::setManualClassDescription(const QString &manualClassDescription)
{
    m_manualClassDescription = manualClassDescription;
}

std::unique_ptr<ManualClass> ManualClass::fromXml(const dataadvice::ManualClass &mclass)
{
    auto model = std::make_unique<ManualClass>();
    if (mclass.ManualClassCode().present())
            model->setManualClassCode(QString::fromStdString(mclass.ManualClassCode().get()));
    if (mclass.ManualClassDescription().present())
        model->setManualClassDescription(QString::fromStdString(mclass.ManualClassDescription().get()));
    if (mclass.PercentDeviation().present())
        model->setDeviation(mclass.PercentDeviation().get());
    return model;
}

double ManualClass::deviation() const
{
    return m_deviation;
}

void ManualClass::setDeviation(double deviation)
{
    m_deviation = deviation;
}
