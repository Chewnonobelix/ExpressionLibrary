#ifndef MINUSEXPRESSION
#define MINUSEXPRESSION

#include "Core/binaryexpression.h"

template<class T>
class MinusExpression final: public BinaryExpression<T>
{
public:
    MinusExpression() = default;
    MinusExpression(const MinusExpression<T>&) = default;
    ~MinusExpression() override = default;

    T evaluate() const override
    {
        return this->e1()->evaluate() - this->e2()->evaluate();
    }

    QSharedPointer<Expression<T>> clone() const override
    {
        return DesignPattern::factory<MinusExpression<T>>(*this);
    }
};

#endif // MINUSEXPRESSION

