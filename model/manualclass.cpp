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
