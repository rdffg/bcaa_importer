#ifndef LEGALDESCRIPTION_H
#define LEGALDESCRIPTION_H

#include "QDjangoModel.h"
#include "model/folio.h"

#define LEGAL_DESCR_FOLIO_PROPERTY "folio"
namespace model {
class LegalDescription : public QDjangoModel {
    Q_OBJECT
    Q_PROPERTY(QString formattedLegalDescription READ formattedLegalDescription WRITE setFormattedLegalDescription)
    Q_PROPERTY(QString PID READ PID WRITE setPID)
    Q_PROPERTY(QString lot READ lot WRITE setLot)
    Q_PROPERTY(QString strataLot READ strataLot WRITE setStrataLot)
    Q_PROPERTY(QString parcel READ parcel WRITE setParcel)
    Q_PROPERTY(QString block READ block WRITE setBlock)
    Q_PROPERTY(QString subBlock READ subBlock WRITE setSubBlock)
    Q_PROPERTY(QString plan READ plan WRITE setPlan)
    Q_PROPERTY(QString subLot READ subLot WRITE setSubLot)
    Q_PROPERTY(QString part1 READ part1 WRITE setPart1)
    Q_PROPERTY(QString part2 READ part2 WRITE setPart2)
    Q_PROPERTY(QString part3 READ part3 WRITE setPart3)
    Q_PROPERTY(QString part4 READ part4 WRITE setPart4)
    Q_PROPERTY(QString districtLot READ districtLot WRITE setDistrictLot)
    Q_PROPERTY(QString legalSubdivision READ legalSubdivision WRITE setLegalSubdivision)
    Q_PROPERTY(QString section READ section WRITE setSection)
    Q_PROPERTY(QString township READ township WRITE setTownship)
    Q_PROPERTY(QString range READ range WRITE setRange)
    Q_PROPERTY(QString meridian READ meridian WRITE setMeridian)
    Q_PROPERTY(QString meridianShort READ meridianShort WRITE setMeridianShort)
    Q_PROPERTY(QString BCAGroup READ BCAGroup WRITE setBCAGroup)
    Q_PROPERTY(QString landDistrict READ landDistrict WRITE setLandDistrict)
    Q_PROPERTY(QString landDistrictDescription READ landDistrictDescription WRITE setLandDistrictDescription)
    Q_PROPERTY(QString portion READ portion WRITE setPortion)
    Q_PROPERTY(QString exceptPlan READ exceptPlan WRITE setExceptPlan)
    Q_PROPERTY(QString firstNationsReserveNumber READ firstNationsReserveNumber WRITE setFirstNationsReserveNumber)
    Q_PROPERTY(QString firstNationsReserveDescription READ firstNationsReserveDescription WRITE setFirstNationsReserveDescription)
    Q_PROPERTY(QString leaseLicenceNumber READ leaseLicenceNumber WRITE setLeaseLicenceNumber)
    Q_PROPERTY(QString landBranchFileNumber READ landBranchFileNumber WRITE setLandBranchFileNumber)
    Q_PROPERTY(QString airSpaceParcelNumber READ airSpaceParcelNumber WRITE setAirSpaceParcelNumber)
    Q_PROPERTY(QString legalText READ legalText WRITE setLegalText)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=legal_description")
    Q_CLASSINFO("formattedLegalDescription", "null=true")
    Q_CLASSINFO("PID", "null=true")
    Q_CLASSINFO("lot", "null=true")
    Q_CLASSINFO("strataLot", "null=true")
    Q_CLASSINFO("parcel", "null=true")
    Q_CLASSINFO("block", "null=true")
    Q_CLASSINFO("subBlock", "null=true")
    Q_CLASSINFO("plan", "null=true")
    Q_CLASSINFO("subLot", "null=true")
    Q_CLASSINFO("part1", "null=true")
    Q_CLASSINFO("part2", "null=true")
    Q_CLASSINFO("part3", "null=true")
    Q_CLASSINFO("part4", "null=true")
    Q_CLASSINFO("districtLot", "null=true")
    Q_CLASSINFO("legalSubdivision", "null=true")
    Q_CLASSINFO("section", "null=true")
    Q_CLASSINFO("township", "null=true")
    Q_CLASSINFO("range", "null=true")
    Q_CLASSINFO("meridian", "null=true")
    Q_CLASSINFO("meridianShort", "null=true")
    Q_CLASSINFO("BCAGroup", "null=true")
    Q_CLASSINFO("landDistrict", "null=true")
    Q_CLASSINFO("landDistrictDescription", "null=true")
    Q_CLASSINFO("portion", "null=true")
    Q_CLASSINFO("exceptPlan", "null=true")
    Q_CLASSINFO("firstNationsReserveNumber", "null=true")
    Q_CLASSINFO("firstNationsReserveDescription", "null=true")
    Q_CLASSINFO("leaseLicenceNumber", "null=true")
    Q_CLASSINFO("landBranchFileNumber", "null=true")
    Q_CLASSINFO("airSpaceParcelNumber", "null=true")
    Q_CLASSINFO("legalText", "null=true")
    Q_CLASSINFO("folio", "on_delete=cascade")



public:
  LegalDescription(QObject *parent = 0);
  QString formattedLegalDescription() const;
  void setFormattedLegalDescription(const QString &formattedLegalDescription);

  QString PID() const;
  void setPID(const QString &PID);

  QString lot() const;
  void setLot(const QString &lot);

  QString strataLot() const;
  void setStrataLot(const QString &strataLot);

  QString parcel() const;
  void setParcel(const QString &parcel);

  QString block() const;
  void setBlock(const QString &block);

  QString subBlock() const;
  void setSubBlock(const QString &subBlock);

  QString plan() const;
  void setPlan(const QString &plan);

  QString subLot() const;
  void setSubLot(const QString &subLot);

  QString part1() const;
  void setPart1(const QString &part1);

  QString part2() const;
  void setPart2(const QString &part2);

  QString part3() const;
  void setPart3(const QString &part3);

  QString part4() const;
  void setPart4(const QString &part4);

  QString districtLot() const;
  void setDistrictLot(const QString &districtLot);

  QString legalSubdivision() const;
  void setLegalSubdivision(const QString &legalSubdivision);

  QString section() const;
  void setSection(const QString &section);

  QString township() const;
  void setTownship(const QString &township);

  QString range() const;
  void setRange(const QString &range);

  QString meridian() const;
  void setMeridian(const QString &meridian);

  QString meridianShort() const;
  void setMeridianShort(const QString &meridianShort);

  QString BCAGroup() const;
  void setBCAGroup(const QString &BCAGroup);

  QString landDistrict() const;
  void setLandDistrict(const QString &landDistrict);

  QString landDistrictDescription() const;
  void setLandDistrictDescription(const QString &landDistrictDescription);

  QString portion() const;
  void setPortion(const QString &portion);

  QString exceptPlan() const;
  void setExceptPlan(const QString &exceptPlan);

  QString firstNationsReserveNumber() const;
  void setFirstNationsReserveNumber(const QString &firstNationsReserveNumber);

  QString firstNationsReserveDescription() const;
  void setFirstNationsReserveDescription(const QString &firstNationsReserveDescription);

  QString leaseLicenceNumber() const;
  void setLeaseLicenceNumber(const QString &leaseLicenceNumber);

  QString landBranchFileNumber() const;
  void setLandBranchFileNumber(const QString &landBranchFileNumber);

  QString airSpaceParcelNumber() const;
  void setAirSpaceParcelNumber(const QString &airSpaceParcelNumber);

  QString legalText() const;
  void setLegalText(const QString &legalText);

  model::Folio *folio() const;
  void setFolio(model::Folio *folio);

private:
  QString m_formattedLegalDescription;
  QString m_PID;
  QString m_lot;
  QString m_strataLot;
  QString m_parcel;
  QString m_block;
  QString m_subBlock;
  QString m_plan;
  QString m_subLot;
  QString m_part1;
  QString m_part2;
  QString m_part3;
  QString m_part4;
  QString m_districtLot;
  QString m_legalSubdivision;
  QString m_section;
  QString m_township;
  QString m_range;
  QString m_meridian;
  QString m_meridianShort;
  QString m_BCAGroup;
  QString m_landDistrict;
  QString m_landDistrictDescription;
  QString m_portion;
  QString m_exceptPlan;
  QString m_firstNationsReserveNumber;
  QString m_firstNationsReserveDescription;
  QString m_leaseLicenceNumber;
  QString m_landBranchFileNumber;
  QString m_airSpaceParcelNumber;
  QString m_legalText;
};
}

#endif // LEGALDESCRIPTION_H
