#include "schoolclassconverter.h"
#include "saveerror.h"

static std::set<QString> railwayCodes = std::set<QString> { "24", "25", "26", "28", "60", "69", "70", "77"};
static QString MilitaryManufacturedHome = "04";

std::unique_ptr<model::Valuation> copyValuation(const model::Valuation* const value)
{
    auto val = std::make_unique<model::Valuation>();
    val->setLandValue(value->landValue());
    val->setImprovementValue(value->improvementValue());
    if (!val->save())
        throw SaveError(val->lastError().text());
    return val;
}

void model::FixSchoolValues(
  const std::vector<std::unique_ptr<model::ValuesByETC>>& taxExemptValues,
  PropertyClassValue& schoolValue)
{
  // remove school value if the tax exempt code is 04 (independant power
  // producer or Canadian Forces Manufactured Home property)
  if (std::any_of(taxExemptValues.begin(), taxExemptValues.end(),
                  [](const std::unique_ptr<model::ValuesByETC>& val) {
                    return val->taxExemptCode() == MilitaryManufacturedHome;
                  })) {
      auto val = schoolValue.taxExemptValues();
      if (val != NULL)
      {
          val->setLandValue(schoolValue.grossValues()->landValue());
          val->setImprovementValue(schoolValue.grossValues()->improvementValue());
          if (!val->save())
          {
              throw SaveError(val->lastError().text());
          }
      }
      val = schoolValue.netValues();
      if (val != NULL)
      {
          val->setLandValue(0);
          val->setImprovementValue(0);
          val = schoolValue.netValues();
          if (!schoolValue.netValues()->save())
              throw SaveError(schoolValue.netValues()->lastError().text());
      }
  }
}

std::unique_ptr<model::PropertyClassValue> model::createHospitalValuesFromSchoolValues(
        const model::PropertyClassValue &schoolValue,
        const model::PropertyClassValue &generalValue,
        const std::vector<std::unique_ptr<model::ValuesByETC>>& taxExemptValues)
{
    auto hospitalValue = std::make_unique<model::PropertyClassValue>();
    if (schoolValue.folio() != NULL)
        hospitalValue->setFolio(schoolValue.folio());
    hospitalValue->setValueType(model::PropertyClassValueType::getModel(model::PropertyClassValueType::Hospital));
    hospitalValue->setPropertyClassCode(schoolValue.propertyClassCode());
    hospitalValue->setPropertyClassDescription(schoolValue.propertyClassDescription());
    hospitalValue->setPropertySubClassCode(schoolValue.propertySubClassCode());
    hospitalValue->setPropertySubClassDescription(schoolValue.propertyClassDescription());
    // if any of the tax exempt codes are a railway code, the hospital tax should be
    // the same as the general tax values
    if (std::any_of(taxExemptValues.begin(), taxExemptValues.end(), [](const std::unique_ptr<model::ValuesByETC> &val) -> bool
        {
                    return  railwayCodes.find(val->taxExemptCode()) != railwayCodes.end();
        }))
    {
        if (generalValue.grossValues() != NULL)
            hospitalValue->setGrossValues(copyValuation(generalValue.grossValues()));
        if (generalValue.netValues() != NULL)
            hospitalValue->setNetValues(copyValuation(generalValue.netValues()));
        if (generalValue.taxExemptValues() != NULL)
            hospitalValue->setTaxExemptValues(copyValuation(generalValue.taxExemptValues()));
    }
    else // otherwise use the school tax values
    {
        if (schoolValue.grossValues() != NULL)
            hospitalValue->setGrossValues(copyValuation(schoolValue.grossValues()));
        if (schoolValue.netValues() != NULL)
            hospitalValue->setNetValues(copyValuation(schoolValue.netValues()));
        if (schoolValue.taxExemptValues() != NULL)
            hospitalValue->setTaxExemptValues(copyValuation(schoolValue.taxExemptValues()));
    }

    return hospitalValue;

} // namespace model
