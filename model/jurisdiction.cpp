#include "jurisdiction.h"

using namespace model;
Jurisdiction::Jurisdiction(QObject *parent): QDjangoModel(parent) {
    //setForeignKey(ASSESSMENT_AREA_PROPERTY, new AssessmentArea());
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

AssessmentArea *Jurisdiction::assessmentArea()
{
    return qobject_cast<AssessmentArea *>(foreignKey(ASSESSMENT_AREA_PROPERTY));
}

void Jurisdiction::setAssessmentArea(AssessmentArea *area) {
    setForeignKey(ASSESSMENT_AREA_PROPERTY, area);
}

void Jurisdiction::setAssessmentArea(std::shared_ptr<AssessmentArea> area) {
    setForeignKey(ASSESSMENT_AREA_PROPERTY, area.get());
}

model::Jurisdiction *Jurisdiction::fromXml(dataadvice::Jurisdiction const &jurisdiction)
{
    auto jurisdictionmodel = new model::Jurisdiction();
    jurisdictionmodel->setCode(QString::fromStdString(jurisdiction.JurisdictionCode()));
    if (jurisdiction.JurisdictionDescription().present())
        jurisdictionmodel->setDescription(
                    QString::fromStdString(jurisdiction.JurisdictionDescription().get()));
    return jurisdictionmodel;
}
