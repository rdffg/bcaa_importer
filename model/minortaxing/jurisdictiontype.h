#ifndef JURISDICTIONNAME_H
#define JURISDICTIONNAME_H
#include "QDjangoModel.h"

namespace model {
namespace minortaxing {
class JurisdictionType : public QDjangoModel {
  Q_OBJECT
  Q_PROPERTY(TaxingJurisdictionType type READ type WRITE setType)
  Q_PROPERTY(QString description READ description WRITE setDescription)
  Q_CLASSINFO("__meta__", "db_table=jurisdiction_type")
  Q_CLASSINFO("type", "primary_key=true")

public:
  explicit JurisdictionType(QObject *parent = 0);

  enum TaxingJurisdictionType {
      ElectoralArea = 1,
      ServiceArea,
      Defined,
      SpecifiedRegional,
      SpecifiedMunicipal,
      LocalArea,
      GeneralService,
      ImprovementDistrict,
      IslandTrust
  };
  Q_ENUM(TaxingJurisdictionType)

  TaxingJurisdictionType type() const;
  void setType(const TaxingJurisdictionType &type);

  QString description() const;
  void setDescription(const QString &description);

private:
  TaxingJurisdictionType m_type;
  QString m_description;
};
}
}
#endif // JURISDICTIONNAME_H
