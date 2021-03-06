#ifndef MODEL_MANAGEDFOREST_H
#define MODEL_MANAGEDFOREST_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class ManagedForest : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString managedForestNumber READ managedForestNumber WRITE setManagedForestNumber)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)
    Q_CLASSINFO("__meta__", "db_table=managed_forest")
    Q_CLASSINFO("id", "primary_key=true max_length=32")
    Q_CLASSINFO("folio", "on_delete=cascade")
    Q_CLASSINFO("managedForestNumber", "null=true max_length=255")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit ManagedForest(QObject *parent = 0);

    QString managedForestNumber() const;
    void setManagedForestNumber(const QString &managedForestNumber);

    Folio* folio() const;
    void setFolio(Folio* folio);

    QString id() const;
    void setId(const QString &id);

private:
    QString m_id;
    QString m_managedForestNumber;
};

} // namespace model

#endif // MODEL_MANAGEDFOREST_H
