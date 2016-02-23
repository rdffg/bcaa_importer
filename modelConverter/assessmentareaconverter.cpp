#include "assessmentareaconverter.h"

using namespace converter;
std::shared_ptr<AssessmentArea> AssessmentAreaConverter::convert(dataadvice::AssessmentArea &xml_model)
{
    auto aa = std::shared_ptr<AssessmentArea>(new AssessmentArea());
    aa->setAssessmentAreaCode(QString::fromStdString(xml_model.AssessmentAreaCode()));
    if (xml_model.AssessmentAreaDescription().present())
            aa->setAssessmentAreaDescription(
                        QString::fromStdString(
                            xml_model.AssessmentAreaDescription().get()));
    return aa;
}
