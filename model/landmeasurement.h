#ifndef LANDMEASUREMENT_H
#define LANDMEASUREMENT_H
#include "QDjangoModel.h"
#include "model/foliodescription.h"

#define LANDMEASUREMENT_FOLIODESCRIPTION_PROPERTY "folioDescription"

namespace model {
class LandMeasurement : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString landDimensionType READ landDimensionType WRITE setLandDimensionType)
    Q_PROPERTY(QString landDimensionTypeDescription READ landDimensionTypeDescription WRITE setLandDimensionTypeDescription)
    Q_PROPERTY(QString landDimension READ landDimension WRITE setLandDimension)
    Q_PROPERTY(QString landWidth READ landWidth WRITE setLandWidth)
    Q_PROPERTY(QString landDepth READ landDepth WRITE setLandDepth)
    Q_PROPERTY(model::FolioDescription* folioDescription READ folioDescription WRITE setFolioDescription)

    Q_CLASSINFO("__meta__", "db_table=land_measurement")
    Q_CLASSINFO("landDimensionType", "null=true")
    Q_CLASSINFO("landDimensionTypeDescription", "null=true")
    Q_CLASSINFO("landDimension", "null=true")
    Q_CLASSINFO("landWidth", "null=true")
    Q_CLASSINFO("landDepth", "null=true")
    Q_CLASSINFO("folioDescription", "null=true on_delete=cascade")

public:
    explicit LandMeasurement(QObject *parent=0);
    QString landDimensionType() const;
    void setLandDimensionType(const QString &landDimensionType);

    QString landDimensionTypeDescription() const;
    void setLandDimensionTypeDescription(const QString &landDimensionTypeDescription);

    QString landDimension() const;
    void setLandDimension(const QString &landDimension);

    QString landWidth() const;
    void setLandWidth(const QString &landWidth);

    QString landDepth() const;
    void setLandDepth(const QString &landDepth);

    model::FolioDescription* folioDescription() const;
    void setFolioDescription(model::FolioDescription* folioDescription);

 //   std::unique_ptr<LandMeasurement> fromXml(const dataadvice::LandMeasurement &measurement);

private:
    QString m_landDimensionType;
    QString m_landDimensionTypeDescription;
    QString m_landDimension;
    QString m_landWidth;
    QString m_landDepth;
};
}
#endif // LANDMEASUREMENT_H
