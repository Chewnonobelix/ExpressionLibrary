#ifndef UNARYEXPRESSION
#define UNARYEXPRESSION

#include "expression.h"

template <class T, class R>
class UnaryExpression: public Expression<T, R>
{
private:
    QSharedPointer<Expression<T, R>> m_e;

public:
    UnaryExpression() = default;

    UnaryExpression(const UnaryExpression<T, R>& e): Expression<T, R>(e), m_e(e.m_e->clone())
    {}

    ~UnaryExpression() override = default;

    QSharedPointer<Expression<T, R>> e() const
    {
        return m_e;
    }

    void setE(QSharedPointer<Expression<T, R>> e)
    {
        m_e = e;
    }
};

#endif // UNARYEXPRESSION

