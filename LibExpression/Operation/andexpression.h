#ifndef ANDEXPRESSION
#define ANDEXPRESSION

#include "../Core/expression_global.h"
#include "../Core/binaryexpression.h"

class EXPRESSIONSHARED_EXPORT AndExpression final: public BinaryExpression<bool>
{
public:
    AndExpression() = default;
    AndExpression(const AndExpression&) = default;
    ~AndExpression() override = default;

    bool evaluate() const override;

    QSharedPointer<Expression<bool>> clone() const override;
};

#endif // ANDEXPRESSION

