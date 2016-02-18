#include "jurisdiction.h"

Jurisdiction::Jurisdiction(QObject *parent): QDjangoModel(parent) {

}

QString Jurisdiction::code()
{
    return m_code;
}

void Jurisdiction::setCode(QString code)
{
    m_code = code;
}

QString Jurisdiction::description()
{
    return m_description;
}

void Jurisdiction::setDescription(QString desc)
{
    m_description = desc;
}
