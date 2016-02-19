#include "assessmentarea.h"

AssessmentArea::AssessmentArea(QObject *parent) : QDjangoModel(parent)
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
