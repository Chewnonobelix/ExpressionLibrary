#ifndef EQUIVALENTEXPRESSION
#define EQUIVALENTEXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

class EXPRESSIONSHARED_EXPORT EquivalentExpression final: public BinaryExpression<bool>
{
public:
    EquivalentExpression() = default;
    EquivalentExpression(const EquivalentExpression&) = default;
    ~EquivalentExpression() override = default;

    bool evaluate() const override;
    EquivalentExpression* clone() const override;
};
#endif // EQUIVALENTEXPRESSION

