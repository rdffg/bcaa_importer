#include "sale.h"

namespace model {

Sale::Sale(QObject *parent) : QDjangoModel(parent)
  , m_conveyancePrice(0)
{

}

QString Sale::documentNumber() const
{
    return m_documentNumber;
}

void Sale::setDocumentNumber(const QString &documentNumber)
{
    m_documentNumber = documentNumber;
}

QDate Sale::conveyanceDate() const
{
    return m_conveyanceDate;
}

void Sale::setConveyanceDate(const QDate &conveyanceDate)
{
    m_conveyanceDate = conveyanceDate;
}

double Sale::conveyancePrice() const
{
    return m_conveyancePrice;
}

void Sale::setConveyancePrice(double conveyancePrice)
{
    m_conveyancePrice = conveyancePrice;
}

QString Sale::conveyanceType() const
{
    return m_conveyanceType;
}

void Sale::setConveyanceType(const QString &conveyanceType)
{
    m_conveyanceType = conveyanceType;
}

QString Sale::conveyanceTypeDescription() const
{
    return m_conveyanceTypeDescription;
}

void Sale::setConveyanceTypeDescription(const QString &conveyanceTypeDescription)
{
    m_conveyanceTypeDescription = conveyanceTypeDescription;
}

QString Sale::rejectReasonCode() const
{
    return m_rejectReasonCode;
}

void Sale::setRejectReasonCode(const QString &code)
{
    m_rejectReasonCode = code;
}

QString Sale::rejectReasonDescription() const
{
    return m_rejectReasonDescription;
}

void Sale::setRejectReasonDescription(const QString &rejectReasonDescription)
{
    m_rejectReasonDescription = rejectReasonDescription;
}

Folio *Sale::folio() const
{
    return qobject_cast<Folio *>(foreignKey("folio"));
}

void Sale::setFolio(Folio *folio)
{
    setForeignKey("folio", folio);
}

void Sale::setFolio(std::unique_ptr<Folio> folio)
{
    setForeignKey("folio", folio.get());
}

//std::unique_ptr<Sale> Sale::fromXml(const dataadvice::Sale &sale)
//{
//    auto model = std::make_unique<Sale>();
//    if (sale.ConveyanceType().present())
//        model->setConveyanceType(QString::fromStdString(sale.ConveyanceType().get()));
//    if (sale.ConveyancePrice().present())
//        model->setConveyancePrice(sale.ConveyancePrice().get());
//    if (sale.ConveyanceDate().present())
//        model->setConveyanceDate(QDate(sale.ConveyanceDate().get().year()
//                                       , sale.ConveyanceDate().get().month()
//                                       , sale.ConveyanceDate().get().day()));
//    if (sale.DocumentNumber().present())
//        model->setDocumentNumber(QString::fromStdString(sale.DocumentNumber().get()));
//    if (sale.RejectReasonCode().present())
//        model->setRejectReasonCode(QString::fromStdString(sale.RejectReasonCode().get()));
//    if (sale.RejectReasonDescription().present())
//        model->setRejectReasonDescription(QString::fromStdString(sale.RejectReasonDescription().get()));
//    return model;
//}
} // namespace model

