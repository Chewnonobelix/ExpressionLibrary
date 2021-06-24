#pragma once

#include <Core/alternativebinaryexpression.h>

template <class T>
class SuperiorExpression final: public AlternativeBinaryExpression<T, bool>
{
public:
    SuperiorExpression() = default;
    SuperiorExpression(const SuperiorExpression&) = default;
    ~SuperiorExpression() override = default;

    bool evaluate() const override
    {
        return this->e1()->evaluate() > this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, bool>> clone() const override
    {
        return QSharedPointer<SuperiorExpression<T>>::create(*this);
    }
};
