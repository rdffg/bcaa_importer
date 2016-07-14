#include "assessmentarea.h"

using namespace model;
AssessmentArea::AssessmentArea(QObject *parent) : BcaaModel(parent)
  , m_assessmentAreaCode(QString())
  , m_assessmentAreaDescription(QString())
{

}

QString AssessmentArea::assessmentAreaCode()
{
    return m_assessmentAreaCode;
}

void AssessmentArea::setAssessmentAreaCode(QString area)
{
    m_assessmentAreaCode = area;
}

QString AssessmentArea::assessmentAreaDescription()
{
    return m_assessmentAreaDescription;
}

void AssessmentArea::setAssessmentAreaDescription(QString descr)
{
    m_assessmentAreaDescription = descr;
}

//model::AssessmentArea* AssessmentArea::fromXml(dataadvice::AssessmentArea const &xml_model)
//{
//    auto aa = new model::AssessmentArea();
//    aa->setAssessmentAreaCode(QString::fromStdString(xml_model.AssessmentAreaCode()));
//    if (xml_model.AssessmentAreaDescription().present())
//            aa->setAssessmentAreaDescription(
//                        QString::fromStdString(
//                            xml_model.AssessmentAreaDescription().get()));
//    return aa;
//}
