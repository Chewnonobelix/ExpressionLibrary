#ifndef ANDEXPRESSION
#define ANDEXPRESSION

#include "Core/expression_global.h"
#include "Core/binaryexpression.h"

class EXPRESSIONSHARED_EXPORT AndExpression final: public BinaryExpression<bool, bool>
{
public:
    AndExpression() = default;
    AndExpression(const AndExpression&) = default;
    ~AndExpression() override = default;

    bool evaluate() const override;

    QSharedPointer<Expression<bool, bool>> clone() const override;
};

#endif // ANDEXPRESSION

