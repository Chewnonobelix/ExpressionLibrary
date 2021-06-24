#ifndef OREXPRESSION
#define OREXPRESSION

#include "Core/expression_global.h"
#include "Core/binaryexpression.h"

class EXPRESSIONSHARED_EXPORT OrExpression final: public BinaryExpression<bool, bool>
{
public:
    OrExpression() = default;
    OrExpression(const OrExpression&) = default;
    ~OrExpression() override = default;

    bool evaluate() const override;

    QSharedPointer<Expression<bool, bool>> clone() const override;
};
#endif // OREXPRESSION

