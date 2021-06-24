#ifndef UNARYEXPRESSION
#define UNARYEXPRESSION

#include "expression.h"

template<class T>
class UnaryExpression: public Expression<T>
{
private:
    QSharedPointer<Expression<T>> m_e;

public:
    UnaryExpression() = default;

    UnaryExpression(const UnaryExpression<T>& e): Expression<T>(e), m_e(e.m_e->clone())
    {}

    ~UnaryExpression() override = default;

    QSharedPointer<Expression<T>> e() const
    {
        return m_e;
    }

    void setE(QSharedPointer<Expression<T>> e)
    {
        m_e = e;
    }
};

#endif // UNARYEXPRESSION

