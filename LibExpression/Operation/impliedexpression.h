#ifndef IMPLIESEXPRESSION
#define IMPLIESEXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

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

