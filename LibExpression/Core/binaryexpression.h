#ifndef BINARYEXPRESSION
#define BINARYEXPRESSION

#include "expression.h"

template<class T>
class BinaryExpression: public Expression<T>
{
private:
    QSharedPointer<Expression<T>> m_e1;
    QSharedPointer<Expression<T>> m_e2;

public:
    BinaryExpression() = default;
    BinaryExpression(const BinaryExpression<T>& e): Expression<T>(e), m_e1(e.m_e1->clone()), m_e2(e.m_e2->clone())
    {}

    ~BinaryExpression() override = default;

    QSharedPointer<Expression<T>> e1() const
    {
        return m_e1;
    }

    QSharedPointer<Expression<T>> e2() const
    {
        return m_e2;
    }

    void setE1(QSharedPointer<Expression<T>> e)
    {
        m_e1 = e;
    }

    void setE2(QSharedPointer<Expression<T>> e)
    {
        m_e2 = e;
    }
};

#endif // BINARYEXPRESSION

