#include "bcaafilereader.h"
#include "QApplication"

std::unique_ptr<dataadvice::DataAdvice> BCAAFileReader::openFile(const QString &path) {
    std::unique_ptr<dataadvice::DataAdvice> da;
    xml_schema::properties props;
    QUrl xsd_path = QUrl::fromLocalFile(
                QApplication::applicationDirPath() + QDir::separator() + "DataAdvice.xsd");
    props.schema_location("http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd"
                          , xsd_path.toString().toStdString());
    da = dataadvice::DataAdvice_ (path.toStdString(), 0 ,props);
    return da;
}
