#ifndef SCHOOLCLASSCONVERTER_H
#define SCHOOLCLASSCONVERTER_H
#include "model/propertyclassvalue.h"
#include "model/valuesbyetc.h"
#include <set>

namespace model {

/*
 * @brief separates creates hospital tax valuations from school valuations
 * 		and tax exempt values
 */
std::unique_ptr<PropertyClassValue> createHospitalValuesFromSchoolValues(
        const PropertyClassValue &schoolValue,
        const PropertyClassValue &generalValue,
        const std::vector<std::unique_ptr<model::ValuesByETC>>& taxExemptValues);

void FixSchoolValues(
        const std::vector<std::unique_ptr<model::ValuesByETC>>& taxExemptValues,
        PropertyClassValue &schoolValue);

} // namespace model

#endif // SCHOOLCLASSCONVERTER_H
