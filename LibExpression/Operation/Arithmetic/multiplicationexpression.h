#ifndef MULTIPLICATIONEXPRESSION
#define MULTIPLICATIONEXPRESSION

#include "Core/binaryexpression.h"

template<class T>
class MultiplicationExpression final: public BinaryExpression<T>
{
public:
    MultiplicationExpression() = default;
    MultiplicationExpression(const MultiplicationExpression<T>&) = default;
    ~MultiplicationExpression() override = default;

    T evaluate() const override
    {
        return this->e1()->evaluate() * this->e2()->evaluate();
    }

    QSharedPointer<Expression<T>> clone() const override
    {
        return QSharedPointer<MultiplicationExpression<T>>::create(*this);
    }
};

#endif // MULTIPLICATIONEXPRESSION

