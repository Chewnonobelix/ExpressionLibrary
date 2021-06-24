#ifndef VALUEEXPRESSION
#define VALUEEXPRESSION

#include "expression.h"
#include "designpattern.h"

template <class T>
class  ValueExpression: public Expression<T, T>
{
protected:
    T m_value;

public:
    ValueExpression() = default;

    ValueExpression(const ValueExpression<T>&) = default;

    ~ValueExpression() override = default ;


    void set(const T& value)
    {
        m_value = value;
    }

    T evaluate() const override
    {
        return m_value;
    }

    QSharedPointer<Expression<T, T>> clone() const override
    {
        return DesignPattern::factory<ValueExpression<T>>(*this);
    }
};

#endif // VALUEEXPRESSION

