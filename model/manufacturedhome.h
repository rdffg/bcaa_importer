#ifndef MODEL_MANUFACTUREDHOME_H
#define MODEL_MANUFACTUREDHOME_H

#include <QDjangoModel.h>
#include <memory>
#include "model/folio.h"

namespace model {

class ManufacturedHome : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString mhRegistryNumber READ mhRegistryNumber WRITE setMhRegistryNumber)
    Q_PROPERTY(QString mhBayNumber READ mhBayNumber WRITE setMhBayNumber)
    Q_PROPERTY(QString mhPark READ mhPark WRITE setMhPark)
    Q_PROPERTY(QString mhParkRollNumber READ mhParkRollNumber WRITE setMhParkRollNumber)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=manufactured_home")
    Q_CLASSINFO("mhRegistryNumber", "null=true")
    Q_CLASSINFO("mhBayNumber", "null=true")
    Q_CLASSINFO("mhPark", "null=true")
    Q_CLASSINFO("mhParkRollNumber", "null=true")
    Q_CLASSINFO("folio", "on_delete=cascade")

public:
    explicit ManufacturedHome(QObject *parent = 0);

    QString mhRegistryNumber() const;
    void setMhRegistryNumber(const QString &mhRegistryNumber);

    QString mhBayNumber() const;
    void setMhBayNumber(const QString &mhBayNumber);

    QString mhPark() const;
    void setMhPark(const QString &mhPark);

    QString mhParkRollNumber() const;
    void setMhParkRollNumber(const QString &mhParkRollNumber);

    Folio *folio() const;
    void setFolio(Folio *folio);
    void setFolio(std::unique_ptr<Folio> folio);


signals:

public slots:
private:
    QString m_mhRegistryNumber;
    QString m_mhBayNumber;
    QString m_mhPark;
    QString m_mhParkRollNumber;
};

} // namespace model

#endif // MODEL_MANUFACTUREDHOME_H
