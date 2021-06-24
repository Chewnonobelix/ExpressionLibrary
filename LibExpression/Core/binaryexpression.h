#ifndef BINARYEXPRESSION
#define BINARYEXPRESSION

#include "expression.h"

template <class T, class R>
class BinaryExpression: public Expression<T, R>
{
private:
    QSharedPointer<Expression<T, R>> m_e1;
    QSharedPointer<Expression<T, R>> m_e2;

public:
    BinaryExpression<T, R>() = default;
    BinaryExpression<T, R>(const BinaryExpression<T, R>& e): Expression<T, R>(e), m_e1(e.m_e1->clone()), m_e2(e.m_e2->clone())
    {}

    ~BinaryExpression<T, R>() override = default;

    QSharedPointer<Expression<T, R>> e1() const
    {
        return m_e1;
    }

    QSharedPointer<Expression<T, R>> e2() const
    {
        return m_e2;
    }

    void setE1(QSharedPointer<Expression<T, R>> e)
    {
        m_e1 = e;
    }

    void setE2(QSharedPointer<Expression<T, R>> e)
    {
        m_e2 = e;
    }
};

#endif // BINARYEXPRESSION

