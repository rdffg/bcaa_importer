#ifndef MODEL_SALE_H
#define MODEL_SALE_H

#include "folio.h"
#include <QDate>

namespace model {

class Sale : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString documentNumber READ documentNumber WRITE setDocumentNumber)
    Q_PROPERTY(QDate conveyanceDate READ conveyanceDate WRITE setConveyanceDate)
    Q_PROPERTY(double conveyancePrice READ conveyancePrice WRITE setConveyancePrice)
    Q_PROPERTY(QString conveyanceType READ conveyanceType WRITE setConveyanceType)
    Q_PROPERTY(QString conveyanceTypeDescription READ conveyanceTypeDescription WRITE setConveyanceTypeDescription)
    Q_PROPERTY(QString rejectReasonCode READ rejectReasonCode WRITE setRejectReasonCode)
    Q_PROPERTY(QString rejectReasonDescription READ rejectReasonDescription WRITE setRejectReasonDescription)
    Q_PROPERTY(model::Folio* folio READ folio WRITE setFolio)

    Q_CLASSINFO("__meta__", "db_table=sale")
    Q_CLASSINFO("documentNumber", "null=true, max_length=255")
    Q_CLASSINFO("conveyanceDate", "null=true")
    Q_CLASSINFO("conveyancePrice", "null=true")
    Q_CLASSINFO("conveyanceType", "null=true, max_length=16")
    Q_CLASSINFO("conveyanceTypeDescription", "null=true, max_length=255")
    Q_CLASSINFO("rejectReasonCode", "null=true, max_length=16")
    Q_CLASSINFO("rejectReasonDescription", "null=true, max_length=255")
    Q_CLASSINFO("folio", "on_delete=cascade")
public:
    explicit Sale(QObject *parent = 0);

    QString documentNumber() const;
    void setDocumentNumber(const QString &documentNumber);

    QDate conveyanceDate() const;
    void setConveyanceDate(const QDate &conveyanceDate);

    double conveyancePrice() const;
    void setConveyancePrice(double conveyancePrice);

    QString conveyanceType() const;
    void setConveyanceType(const QString &conveyanceType);

    QString conveyanceTypeDescription() const;
    void setConveyanceTypeDescription(const QString &conveyanceTypeDescription);

    QString rejectReasonCode() const;
    void setRejectReasonCode(const QString &code);

    QString rejectReasonDescription() const;
    void setRejectReasonDescription(const QString &rejectReasonDescription);

    Folio *folio() const;
    void setFolio(Folio *folio);
    void setFolio(std::unique_ptr<Folio> folio);

    static std::unique_ptr<Sale> fromXml(const dataadvice::Sale &sale);

signals:

public slots:
private:
    QString m_documentNumber;
    QDate m_conveyanceDate;
    double m_conveyancePrice;
    QString m_conveyanceType;
    QString m_conveyanceTypeDescription;
    QString m_rejectReasonCode;
    QString m_rejectReasonDescription;
};

} // namespace model

#endif // MODEL_SALE_H
