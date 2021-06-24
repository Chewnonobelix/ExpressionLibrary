#pragma once

#include <Core/alternativebinaryexpression.h>

template <class T>
class InferiorExpression final: public AlternativeBinaryExpression<T, bool>
{
public:
    InferiorExpression() = default;
    InferiorExpression(const InferiorExpression&) = default;
    ~InferiorExpression() override = default;

    bool evaluate() const override
    {
        return this->e1()->evaluate() < this->e2()->evaluate();
    }

    QSharedPointer<Expression<T, bool>> clone() const override
    {
        return QSharedPointer<InferiorExpression<T>>::create(*this);
    }
};
