#include "preflight.h"
#include "QDjango.h"
#include "saveerror.h"
#include <QDjangoQuerySet.h>
#include "model/model.h"

void PreFlight::prepareDatabase(const QString &runType)
{
    addOwnershipGroupIdColumn();
    if (runType == "COMP")
    {
        QString queryText = "DELETE FROM folio";
        QDjangoQuerySet<model::Folio> folios;
        if (!folios.remove())
            throw SaveError(folios.lastError().text());
        QDjangoQuerySet<model::Owner> owners;
        if (!owners.remove())
            throw SaveError(owners.lastError().text());


//        auto query = QDjango::database().exec(queryText);
//        if (query.lastError().type() != QSqlError::NoError)
//            throw SaveError(query.lastError().text());
    }
    if (runType == "COMP" || runType == "REVD") {
        std::vector<QString> tables {"property_class_value", "tax_exempt_property_class_value", "valuation"};
        QString queryText;
        for (auto &tab: tables)
        {
        if (QDjango::database().driverName() == "QSQLITE" || tab == "valuation")
            queryText = "DELETE FROM " + tab;
        else
            queryText = "TRUNCATE TABLE " + tab;
        auto query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
            throw SaveError(query.lastError().text());
        }
    }
}

void PreFlight::addOwnershipGroupIdColumn()
{
    QString queryText = "SELECT count(ownership_group_id) FROM ownership_group";
    auto query = QDjango::database().exec(queryText);
    if (query.lastError().type() != QSqlError::NoError)
    {
        queryText = "ALTER TABLE ownership_group ADD ownership_group_id nvarchar(32)";
        query = QDjango::database().exec(queryText);
        if (query.lastError().type() != QSqlError::NoError)
        {
            throw SaveError(query.lastError().text());
        }
    }
}
