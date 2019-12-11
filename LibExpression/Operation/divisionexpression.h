#ifndef DIVISIONEXPRESSION
#define DIVISIONEXPRESSION

#include "binaryexpression.h"

template<class T>
class DivisionExpression final: public BinaryExpression<T>
{
public:
    DivisionExpression() = default;
    DivisionExpression(const DivisionExpression<T>&) = default;
    ~DivisionExpression() override = default;

    T evaluate() const override
    {
        return this->e1()->evaluate() / this->e2()->evaluate();
    }

    DivisionExpression<T>* clone() const override
    {
        return new DivisionExpression<T>(*this);
    }
};

#endif // DIVISIONEXPRESSION

