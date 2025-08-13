#ifndef ADDITIONEXPRESSION
#define ADDITIONEXPRESSION

#include "Core/binaryexpression.h"

template<class T>
class AdditionExpression final: public BinaryExpression<T>
{
public:
    AdditionExpression() = default;
    AdditionExpression(const AdditionExpression<T>&) = default;
    ~AdditionExpression() override = default;

    T evaluate() const override
    {
        return this->e1()->evaluate() + this->e2()->evaluate();
    }

    QSharedPointer<Expression<T>> clone() const override
    {
        return QSharedPointer<AdditionExpression<T>>::create(*this);
    }
};

#endif // ADDITIONEXPRESSION

