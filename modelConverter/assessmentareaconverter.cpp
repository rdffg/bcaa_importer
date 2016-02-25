#include "assessmentareaconverter.h"

using namespace converter;
model::AssessmentArea* AssessmentAreaConverter::convert(dataadvice::AssessmentArea &xml_model)
{
    auto aa = new model::AssessmentArea();
    aa->setAssessmentAreaCode(QString::fromStdString(xml_model.AssessmentAreaCode()));
    if (xml_model.AssessmentAreaDescription().present())
            aa->setAssessmentAreaDescription(
                        QString::fromStdString(
                            xml_model.AssessmentAreaDescription().get()));
    return aa;
}
