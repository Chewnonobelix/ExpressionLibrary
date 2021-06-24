#pragma once

#include "expression.h"

template <class T, class R>
class AlternativeBinaryExpression: public Expression<T, R>
{
private:
    QSharedPointer<Expression<T, T>> m_e1;
    QSharedPointer<Expression<T, T>> m_e2;

public:
    AlternativeBinaryExpression<T, R>() = default;
    AlternativeBinaryExpression<T, R>(const AlternativeBinaryExpression<T, R>& e): Expression<T, R>(e), m_e1(e.m_e1->clone()), m_e2(e.m_e2->clone())
    {}

    ~AlternativeBinaryExpression<T, R>() override = default;

    QSharedPointer<Expression<T, T>> e1() const
    {
        return m_e1;
    }

    QSharedPointer<Expression<T, T>> e2() const
    {
        return m_e2;
    }

    void setE1(QSharedPointer<Expression<T, T>> e)
    {
        m_e1 = e;
    }

    void setE2(QSharedPointer<Expression<T, T>> e)
    {
        m_e2 = e;
    }
};


