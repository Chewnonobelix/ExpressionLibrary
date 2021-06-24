#ifndef DIVISIONEXPRESSION
#define DIVISIONEXPRESSION

#include "Core/binaryexpression.h"

template <class T, class R>
class DivisionExpression final: public BinaryExpression<T, R>
{
public:
    DivisionExpression() = default;
    DivisionExpression(const DivisionExpression<T, R>&) = default;
    ~DivisionExpression() override = default;

    R evaluate() const override
    {
        return this->e1()->evaluate() / this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, R>> clone() const override
    {
        return DesignPattern::factory<DivisionExpression<T, R>>(*this);
    }
};

#endif // DIVISIONEXPRESSION

