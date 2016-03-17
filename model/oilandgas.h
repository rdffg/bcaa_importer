#ifndef MODEL_OILANDGAS_H
#define MODEL_OILANDGAS_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class OilAndGas : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString pipelineProjectNumber READ pipelineProjectNumber WRITE setPipelineProjectNumber)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=oil_and_gas")
    Q_CLASSINFO("pipelineProjectNumber", "null=true")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit OilAndGas(QObject *parent = 0);

    QString pipelineProjectNumber() const;
    void setPipelineProjectNumber(const QString &pipelineProjectNumber);

    Folio *folio() const;
    void setFolio(Folio *folio);
    void setFolio(std::unique_ptr<Folio> folio);

    static std::unique_ptr<OilAndGas> fromXml(const dataadvice::OilAndGas &oil);

private:
    QString m_pipelineProjectNumber;
};

} // namespace model

#endif // MODEL_OILANDGAS_H
