#ifndef NOEXPRESSION
#define NOEXPRESSION

#include "Core/expression_global.h"
#include "Core/unaryexpression.h"

class EXPRESSIONSHARED_EXPORT NoExpression final: public UnaryExpression<bool, bool>
{
public:
    NoExpression() = default;
    NoExpression(const NoExpression&) = default;
    ~NoExpression() override = default;

    QSharedPointer<Expression<bool, bool>> clone() const override;

    bool evaluate() const override;
};

#endif // NOEXPRESSION

