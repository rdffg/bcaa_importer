#ifndef MODEL_FARM_H
#define MODEL_FARM_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class Farm : public QDjangoModel
{

    Q_OBJECT
    Q_PROPERTY(QString farmNumber READ farmNumber WRITE setFarmNumber)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=farm")
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

    static std::unique_ptr<Farm> fromXml(const dataadvice::FolioString255Item &farmNumber);

private:
    QString m_farmNumber;
};

} // namespace model

#endif // MODEL_FARM_H
