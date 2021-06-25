#pragma once

#include <Core/expression.h>

template<class T>
class ComparaisonExpression: public Expression<bool>
{
private:
    QSharedPointer<Expression<T>> m_e1;
    QSharedPointer<Expression<T>> m_e2;

public:
    ComparaisonExpression() = default;
    ComparaisonExpression(const ComparaisonExpression<T>& e): Expression<bool>(e), m_e1(e.m_e1->clone()), m_e2(e.m_e2->clone())
    {}
    ~ComparaisonExpression() = default;

    QSharedPointer<Expression<T>> e1() const {return m_e1;}
    QSharedPointer<Expression<T>> e2() const {return m_e2;}

    void setE1(QSharedPointer<Expression<T>> e)
    {
        m_e1 = e;
    }

    void setE2(QSharedPointer<Expression<T>> e)
    {
        m_e2 = e;
    }
};
