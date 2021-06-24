#ifndef MINUSEXPRESSION
#define MINUSEXPRESSION

#include "Core/binaryexpression.h"

template <class T, class R>
class MinusExpression final: public BinaryExpression<T, R>
{
public:
    MinusExpression() = default;
    MinusExpression(const MinusExpression<T, R>&) = default;
    ~MinusExpression() override = default;

    R evaluate() const override
    {
        return this->e1()->evaluate() - this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, R>> clone() const override
    {
        return DesignPattern::factory<MinusExpression<T, R>>(*this);
    }
};

#endif // MINUSEXPRESSION

