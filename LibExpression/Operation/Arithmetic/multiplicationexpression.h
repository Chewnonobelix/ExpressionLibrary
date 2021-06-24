#ifndef MULTIPLICATIONEXPRESSION
#define MULTIPLICATIONEXPRESSION

#include "Core/binaryexpression.h"

template <class T, class R>
class MultiplicationExpression final: public BinaryExpression<T, R>
{
public:
    MultiplicationExpression() = default;
    MultiplicationExpression(const MultiplicationExpression<T, R>&) = default;
    ~MultiplicationExpression() override = default;

    R evaluate() const override
    {
        return this->e1()->evaluate() * this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, R>> clone() const override
    {
        return DesignPattern::factory<MultiplicationExpression<T, R>>(*this);
    }
};

#endif // MULTIPLICATIONEXPRESSION

