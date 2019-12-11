#ifndef MINUSEXPRESSION
#define MINUSEXPRESSION

#include "binaryexpression.h"

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

    MinusExpression<T>* clone() const override
    {
        return new MinusExpression<T>(*this);
    }
};

#endif // MINUSEXPRESSION

