#ifndef MULTIPLICATIONEXPRESSION
#define MULTIPLICATIONEXPRESSION

#include "binaryexpression.h"

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

    MultiplicationExpression<T>* clone() const override
    {
        return new MultiplicationExpression<T>(*this);
    }
};

#endif // MULTIPLICATIONEXPRESSION

