#ifndef MODEL_MANAGEDFOREST_H
#define MODEL_MANAGEDFOREST_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class ManagedForest : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString managedForestNumber READ managedForestNumber WRITE setManagedForestNumber)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)
    Q_CLASSINFO("__meta__", "db_table=managed_forest")
    Q_CLASSINFO("folio", "on_delete=cascade")
    Q_CLASSINFO("managedForestNumber", "null=true max_length=255")
public:
    explicit ManagedForest(QObject *parent = 0);

    QString managedForestNumber() const;
    void setManagedForestNumber(const QString &managedForestNumber);

    Folio* folio() const;
    void setFolio(Folio* folio);

    static std::unique_ptr<ManagedForest> fromXml(const dataadvice::ManagedForest &forest);

private:
    QString m_managedForestNumber;
};

} // namespace model

#endif // MODEL_MANAGEDFOREST_H
