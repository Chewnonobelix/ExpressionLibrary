#ifndef OREXPRESSION
#define OREXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

class EXPRESSIONSHARED_EXPORT OrExpression final: public BinaryExpression<bool>
{
public:
    OrExpression() = default;
    OrExpression(const OrExpression&) = default;
    ~OrExpression() override = default;

    bool evaluate() const override;

    QSharedPointer<Expression<bool>> clone() const override;
};
#endif // OREXPRESSION

