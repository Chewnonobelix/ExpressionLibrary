#pragma once

#include "comparaisonexpression.h"

template<class T>
class SuperiorExpression: public ComparaisonExpression<T>
{
public:
    SuperiorExpression() = default;
    SuperiorExpression(const SuperiorExpression&) = default;
    ~SuperiorExpression() = default;

    QSharedPointer<Expression<bool>> clone() const override
    {
        return QSharedPointer<SuperiorExpression<T>>::create(*this);
    }

    bool evaluate() const override
    {
        return this->e1()->evaluate() > this->e2()->evaluate();
    }
};
