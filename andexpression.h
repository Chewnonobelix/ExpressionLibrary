#ifndef ANDEXPRESSION
#define ANDEXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

class EXPRESSIONSHARED_EXPORT AndExpression final: public BinaryExpression<bool>
{
public:
    AndExpression() = default;
    AndExpression(const AndExpression&) = default;
    ~AndExpression() override = default;

    bool evaluate() const override;

    AndExpression* clone() const override;
};

#endif // ANDEXPRESSION

