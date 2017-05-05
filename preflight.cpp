#include "preflight.h"
#include "QDjango.h"
#include "saveerror.h"

void PreFlight::prepareDatabase(const QString &runType)
{
    if (runType == "COMP")
    {
        QString queryText = "DELETE FROM folio";
        auto query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
            throw SaveError(query.lastError().text());
    }
    if (runType == "COMP" || runType == "REVD") {
        QString queryText = "TRUNCATE TABLE property_class_value";
        auto query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
            throw SaveError(query.lastError().text());
        queryText = "TRUNCATE TABLE valuation";
        query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
            throw SaveError(query.lastError().text());
    }
}
