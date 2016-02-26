#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H
#include "QDjangoModel.h"
#include "model/foliodescription.h"

#define NEIGHBOURHOOD_FOLIODESCRIPTION_PROPERTY "folioDescription"
namespace  model {
class Neighbourhood : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString neighbourhoodCode READ neighbourhoodCode WRITE setNeighbourhoodCode)
    Q_PROPERTY(QString neighbourhoodDescription READ neighbourhoodDescription WRITE setNeighbourhoodDescription)
    Q_PROPERTY(model::FolioDescription* folioDescription READ folioDescription WRITE setFolioDescription)

    Q_CLASSINFO("__meta__", "db_table=neighbourhood")
    Q_CLASSINFO("neighbourhoodCode", "null=true")
    Q_CLASSINFO("neighbourhoodDescription", "null=true")
    Q_CLASSINFO(NEIGHBOURHOOD_FOLIODESCRIPTION_PROPERTY, "on_delete=cascade")
public:
    explicit Neighbourhood(QObject *parent=0);
    QString neighbourhoodCode() const;
    void setNeighbourhoodCode(const QString &neighbourhoodCode);

    QString neighbourhoodDescription() const;
    void setNeighbourhoodDescription(const QString &neighbourhoodDescription);

    model::FolioDescription *folioDescription() const;
    void setFolioDescription(FolioDescription* descr);

private:
    QString m_neighbourhoodCode;
    QString m_neighbourhoodDescription;
};
}

#endif // NEIGHBOURHOOD_H
