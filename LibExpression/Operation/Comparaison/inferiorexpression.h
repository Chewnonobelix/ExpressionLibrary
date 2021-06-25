#pragma once

#include "comparaisonexpression.h"

template<class T>
class InferiorExpression: public ComparaisonExpression<T>
{
public:
    InferiorExpression() = default;
    InferiorExpression(const InferiorExpression&) = default;
    ~InferiorExpression() = default;

    QSharedPointer<Expression<bool>> clone() const override
    {
        return QSharedPointer<InferiorExpression<T>>::create(*this);
    }

    bool evaluate() const override
    {
        return this->e1()->evaluate() < this->e2()->evaluate();
    }
};
