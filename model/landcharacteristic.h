#ifndef MODEL_LANDCHARACTERISTIC_H
#define MODEL_LANDCHARACTERISTIC_H

#include <QDjangoModel.h>
#include "folio.h"

namespace model {

class LandCharacteristic : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(model::Folio *folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=land_characteristic")
    Q_CLASSINFO("code", "null=true, max_length=16")
    Q_CLASSINFO("description", "null=true, max_length=255")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit LandCharacteristic(QObject *parent = 0);

    QString code() const;
    void setCode(const QString &code);

    QString description() const;
    void setDescription(const QString &description);

    Folio *folio() const;
    void setFolio(Folio *folio);
    void setFolio(std::unique_ptr<Folio> folio);

    static std::unique_ptr<LandCharacteristic> fromXml(const dataadvice::LandCharacteristic &characteristic);

private:
    QString m_code;
    QString m_description;
};

} // namespace model

#endif // MODEL_LANDCHARACTERISTIC_H
