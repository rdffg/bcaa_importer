#include "bcaafilereader.h"

std::unique_ptr<dataadvice::DataAdvice> BCAAFileReader::openFile(const QString &path) {
    std::unique_ptr<dataadvice::DataAdvice> da;
    xml_schema::properties props;
    props.schema_location("http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd", "DataAdvice.xsd");
    da = dataadvice::DataAdvice_ (path.toStdString(), 0 ,props);
    return da;
}
