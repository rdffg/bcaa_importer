#ifndef MODEL_IVALUATION_H
#define MODEL_IVALUATION_H

namespace model {

class IValuation
{
public:
    virtual double landValue() const = 0;
    virtual void setLandValue(const double &value) = 0;

    virtual double improvementValue() const = 0;
    virtual void setImprovementValue(const double &value) = 0;

    virtual ~IValuation() = 0;
};

} // namespace model

#endif // MODEL_IVALUATION_H
