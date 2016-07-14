#include "legaldescription.h"

using namespace model;
LegalDescription::LegalDescription(QObject *parent): QDjangoModel(parent)
{

}

QString LegalDescription::formattedLegalDescription() const
{
    return m_formattedLegalDescription;
}

void LegalDescription::setFormattedLegalDescription(const QString &formattedLegalDescription)
{
    m_formattedLegalDescription = formattedLegalDescription;
}

QString LegalDescription::PID() const
{
    return m_PID;
}

void LegalDescription::setPID(const QString &PID)
{
    m_PID = PID;
}

QString LegalDescription::lot() const
{
    return m_lot;
}

void LegalDescription::setLot(const QString &lot)
{
    m_lot = lot;
}

QString LegalDescription::strataLot() const
{
    return m_strataLot;
}

void LegalDescription::setStrataLot(const QString &strataLot)
{
    m_strataLot = strataLot;
}

QString LegalDescription::parcel() const
{
    return m_parcel;
}

void LegalDescription::setParcel(const QString &parcel)
{
    m_parcel = parcel;
}

QString LegalDescription::block() const
{
    return m_block;
}

void LegalDescription::setBlock(const QString &block)
{
    m_block = block;
}

QString LegalDescription::subBlock() const
{
    return m_subBlock;
}

void LegalDescription::setSubBlock(const QString &subBlock)
{
    m_subBlock = subBlock;
}

QString LegalDescription::plan() const
{
    return m_plan;
}

void LegalDescription::setPlan(const QString &plan)
{
    m_plan = plan;
}

QString LegalDescription::subLot() const
{
    return m_subLot;
}

void LegalDescription::setSubLot(const QString &subLot)
{
    m_subLot = subLot;
}

QString LegalDescription::part1() const
{
    return m_part1;
}

void LegalDescription::setPart1(const QString &part1)
{
    m_part1 = part1;
}

QString LegalDescription::part2() const
{
    return m_part2;
}

void LegalDescription::setPart2(const QString &part2)
{
    m_part2 = part2;
}

QString LegalDescription::part3() const
{
    return m_part3;
}

void LegalDescription::setPart3(const QString &part3)
{
    m_part3 = part3;
}

QString LegalDescription::part4() const
{
    return m_part4;
}

void LegalDescription::setPart4(const QString &part4)
{
    m_part4 = part4;
}

QString LegalDescription::districtLot() const
{
    return m_districtLot;
}

void LegalDescription::setDistrictLot(const QString &districtLot)
{
    m_districtLot = districtLot;
}

QString LegalDescription::legalSubdivision() const
{
    return m_legalSubdivision;
}

void LegalDescription::setLegalSubdivision(const QString &legalSubdivision)
{
    m_legalSubdivision = legalSubdivision;
}

QString LegalDescription::section() const
{
    return m_section;
}

void LegalDescription::setSection(const QString &section)
{
    m_section = section;
}

QString LegalDescription::township() const
{
    return m_township;
}

void LegalDescription::setTownship(const QString &township)
{
    m_township = township;
}

QString LegalDescription::range() const
{
    return m_range;
}

void LegalDescription::setRange(const QString &range)
{
    m_range = range;
}

QString LegalDescription::meridian() const
{
    return m_meridian;
}

void LegalDescription::setMeridian(const QString &meridian)
{
    m_meridian = meridian;
}

QString LegalDescription::meridianShort() const
{
    return m_meridianShort;
}

void LegalDescription::setMeridianShort(const QString &meridianShort)
{
    m_meridianShort = meridianShort;
}

QString LegalDescription::BCAGroup() const
{
    return m_BCAGroup;
}

void LegalDescription::setBCAGroup(const QString &BCAGroup)
{
    m_BCAGroup = BCAGroup;
}

QString LegalDescription::landDistrict() const
{
    return m_landDistrict;
}

void LegalDescription::setLandDistrict(const QString &landDistrict)
{
    m_landDistrict = landDistrict;
}

QString LegalDescription::landDistrictDescription() const
{
    return m_landDistrictDescription;
}

void LegalDescription::setLandDistrictDescription(const QString &landDistrictDescription)
{
    m_landDistrictDescription = landDistrictDescription;
}

QString LegalDescription::portion() const
{
    return m_portion;
}

void LegalDescription::setPortion(const QString &portion)
{
    m_portion = portion;
}

QString LegalDescription::exceptPlan() const
{
    return m_exceptPlan;
}

void LegalDescription::setExceptPlan(const QString &exceptPlan)
{
    m_exceptPlan = exceptPlan;
}

QString LegalDescription::firstNationsReserveNumber() const
{
    return m_firstNationsReserveNumber;
}

void LegalDescription::setFirstNationsReserveNumber(const QString &firstNationsReserveNumber)
{
    m_firstNationsReserveNumber = firstNationsReserveNumber;
}

QString LegalDescription::firstNationsReserveDescription() const
{
    return m_firstNationsReserveDescription;
}

void LegalDescription::setFirstNationsReserveDescription(const QString &firstNationsReserveDescription)
{
    m_firstNationsReserveDescription = firstNationsReserveDescription;
}

QString LegalDescription::leaseLicenceNumber() const
{
    return m_leaseLicenceNumber;
}

void LegalDescription::setLeaseLicenceNumber(const QString &leaseLicenceNumber)
{
    m_leaseLicenceNumber = leaseLicenceNumber;
}

QString LegalDescription::landBranchFileNumber() const
{
    return m_landBranchFileNumber;
}

void LegalDescription::setLandBranchFileNumber(const QString &landBranchFileNumber)
{
    m_landBranchFileNumber = landBranchFileNumber;
}

QString LegalDescription::airSpaceParcelNumber() const
{
    return m_airSpaceParcelNumber;
}

void LegalDescription::setAirSpaceParcelNumber(const QString &airSpaceParcelNumber)
{
    m_airSpaceParcelNumber = airSpaceParcelNumber;
}

QString LegalDescription::legalText() const
{
    return m_legalText;
}

void LegalDescription::setLegalText(const QString &legalText)
{
    m_legalText = legalText;
}

model::Folio *LegalDescription::folio() const {
    return qobject_cast<model::Folio*>(foreignKey(FOLIO_PROPERTY));
}

void LegalDescription::setFolio(model::Folio *folio) {
    setForeignKey(FOLIO_PROPERTY, folio);
}

QString LegalDescription::ntsLocation() const
{
    return m_ntsLocation;
}

void LegalDescription::setNtsLocation(const QString &ntsLocation)
{
    m_ntsLocation = ntsLocation;
}
