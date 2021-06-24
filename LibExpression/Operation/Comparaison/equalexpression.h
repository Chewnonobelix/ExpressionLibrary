#pragma once

#include <Core/alternativebinaryexpression.h>

template <class T>
class EqualExpression final: public AlternativeBinaryExpression<T, bool>
{
public:
    EqualExpression() = default;
    EqualExpression(const EqualExpression&) = default;
    ~EqualExpression() override = default;

    bool evaluate() const override
    {
        return this->e1()->evaluate() == this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, bool>> clone() const override
    {
        return QSharedPointer<EqualExpression<T>>::create(*this);
    }
};
