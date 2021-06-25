#pragma once

#include "comparaisonexpression.h"

template<class T>
class EqualExpression: public ComparaisonExpression<T>
{
public:
    EqualExpression() = default;
    EqualExpression(const EqualExpression&) = default;
    ~EqualExpression() = default;

    QSharedPointer<Expression<bool>> clone() const override
    {
        return QSharedPointer<EqualExpression<T>>::create(*this);
    }

    bool evaluate() const override
    {
        return this->e1()->evaluate() == this->e2()->evaluate();
    }
};
