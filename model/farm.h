#ifndef MODEL_FARM_H
#define MODEL_FARM_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class Farm : public QDjangoModel
{

    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString farmNumber READ farmNumber WRITE setFarmNumber)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=farm")
    Q_CLASSINFO("id", "primary_key=true max_length=32")
    Q_CLASSINFO("farmNumber", "null=true")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit Farm(QObject *parent = 0);

    /**
     * @brief farmNumber - The BCA farm number
     * @return
     */
    QString farmNumber() const;
    void setFarmNumber(const QString &farmNumber);

    Folio *folio() const;
    void setFolio(Folio *folio);
    void setFolio(std::unique_ptr<Folio> folio);
    QString id() const;
    void setId(const QString &id);

private:
    QString m_id;
    QString m_farmNumber;
};

} // namespace model

#endif // MODEL_FARM_H
