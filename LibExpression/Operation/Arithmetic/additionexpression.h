#ifndef ADDITIONEXPRESSION
#define ADDITIONEXPRESSION

#include "Core/binaryexpression.h"

template <class T, class R>
class AdditionExpression final: public BinaryExpression<T, R>
{
public:
    AdditionExpression() = default;
    AdditionExpression(const AdditionExpression<T, R>&) = default;
    ~AdditionExpression() override = default;

    R evaluate() const override
    {
        return this->e1()->evaluate() + this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, R>> clone() const override
    {
        return DesignPattern::factory<AdditionExpression<T, R>>(*this);
    }
};

#endif // ADDITIONEXPRESSION

