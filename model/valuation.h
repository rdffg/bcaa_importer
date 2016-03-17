#ifndef MODEL_VALUATION_H
#define MODEL_VALUATION_H

#include <QDjangoModel.h>
#include "ivaluation.h"
#include <memory>
#include "DataAdvice.hxx"

namespace model {

class Valuation : public QDjangoModel, public IValuation
{
    Q_OBJECT
    Q_PROPERTY(double landValue READ landValue WRITE setLandValue)
    Q_PROPERTY(double improvementValue READ improvementValue WRITE setImprovementValue)

    Q_CLASSINFO("__meta__", "db_table=valuation")
public:
    explicit Valuation(QObject *parent = 0);

signals:

public slots:

    // IValuation interface
public:
    double landValue() const override;
    void setLandValue(const double &value) override;
    double improvementValue() const override;
    void setImprovementValue(const double &value) override;

    static std::unique_ptr<Valuation> fromXml(const dataadvice::Valuation &val);
private:
    double m_landValue;
    double m_improvementValue;
};

} // namespace model

#endif // MODEL_VALUATION_H
