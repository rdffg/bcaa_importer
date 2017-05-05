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
        std::vector<QString> tables {"property_class_value", "valuation", "tax_exempt_property_class_value"};
        QString queryText;
        for (auto &tab: tables)
        {
        if (QDjango::database().driverName() == "QSQLITE")
            queryText = "DELETE FROM " + tab;
        else
            queryText = "TRUNCATE TABLE " + tab;
        auto query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
            throw SaveError(query.lastError().text());
        }
    }
}
