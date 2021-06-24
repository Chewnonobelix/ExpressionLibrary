#ifndef IMPLIESEXPRESSION
#define IMPLIESEXPRESSION

#include "Core/expression_global.h"
#include "Core/binaryexpression.h"

class EXPRESSIONSHARED_EXPORT ImpliesExpression final: public BinaryExpression<bool>
{
public:
    ImpliesExpression() = default;
    ImpliesExpression(const ImpliesExpression&) = default;
    ~ImpliesExpression() override = default;

    bool evaluate() const override;

    QSharedPointer<Expression<bool>> clone() const override;
};
#endif // IMPLIESEXPRESSION

