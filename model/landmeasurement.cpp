#include "landmeasurement.h"

using namespace model;
LandMeasurement::LandMeasurement(QObject *parent): QDjangoModel(parent)
{

}

QString LandMeasurement::landDimensionType() const
{
    return m_landDimensionType;
}

void LandMeasurement::setLandDimensionType(const QString &landDimensionType)
{
    m_landDimensionType = landDimensionType;
}

QString LandMeasurement::landDimensionTypeDescription() const
{
    return m_landDimensionTypeDescription;
}

void LandMeasurement::setLandDimensionTypeDescription(const QString &landDimensionTypeDescription)
{
    m_landDimensionTypeDescription = landDimensionTypeDescription;
}

QString LandMeasurement::landDimension() const
{
    return m_landDimension;
}

void LandMeasurement::setLandDimension(const QString &landDimension)
{
    m_landDimension = landDimension;
}

QString LandMeasurement::landWidth() const
{
    return m_landWidth;
}

void LandMeasurement::setLandWidth(const QString &landWidth)
{
    m_landWidth = landWidth;
}

QString LandMeasurement::landDepth() const
{
    return m_landDepth;
}

void LandMeasurement::setLandDepth(const QString &landDepth)
{
    m_landDepth = landDepth;
}

model::FolioDescription* LandMeasurement::folioDescription() const {
    return qobject_cast<model::FolioDescription *>(foreignKey(LANDMEASUREMENT_FOLIODESCRIPTION_PROPERTY));
}

void LandMeasurement::setFolioDescription(model::FolioDescription* folioDescription) {
    setForeignKey(LANDMEASUREMENT_FOLIODESCRIPTION_PROPERTY, folioDescription);
}

//std::unique_ptr<LandMeasurement> LandMeasurement::fromXml(const dataadvice::LandMeasurement &measurement)
//{
//    auto model = std::make_unique<LandMeasurement>();
//    if (measurement.LandDimensionType().present())
//        model->setLandDimensionType(QString::fromStdString(measurement.LandDimensionType().get()));
//    if (measurement.LandDimensionTypeDescription().present())
//        model->setLandDimensionTypeDescription(QString::fromStdString(measurement.LandDimensionTypeDescription().get()));
//    if (measurement.LandDepth().present())
//        model->setLandDepth(QString::fromStdString(measurement.LandDepth().get()));
//    if (measurement.LandDimension().present())
//        model->setLandDimension(QString::fromStdString(measurement.LandDimension().get()));
//    if (measurement.LandWidth().present())
//        model->setLandWidth(QString::fromStdString(measurement.LandWidth().get()));
//    return model;
//}
