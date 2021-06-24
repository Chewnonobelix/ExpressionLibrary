#ifndef EQUIVALENTEXPRESSION
#define EQUIVALENTEXPRESSION

#include "Core/expression_global.h"
#include "Core/binaryexpression.h"

class EXPRESSIONSHARED_EXPORT EquivalentExpression final: public BinaryExpression<bool, bool>
{
public:
    EquivalentExpression() = default;
    EquivalentExpression(const EquivalentExpression&) = default;
    ~EquivalentExpression() override = default;

    bool evaluate() const override;
    QSharedPointer<Expression<bool, bool>> clone() const override;
};
#endif // EQUIVALENTEXPRESSION

