#ifndef ASSESSMENTAREAMODEL_H
#define ASSESSMENTAREAMODEL_H

#include <memory>
#include "model/assessmentarea.h"
#include "DataAdvice.hxx"

namespace converter {
class AssessmentAreaConverter
{
public:
    static std::shared_ptr<AssessmentArea> convert(dataadvice::AssessmentArea &xml_model);
};
}
#endif // ASSESSMENTAREAMODEL_H
