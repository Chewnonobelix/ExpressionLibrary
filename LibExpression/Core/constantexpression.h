#ifndef CONSTANTEXPRESSION_H
#define CONSTANTEXPRESSION_H

#include "valueexpression.h"

template<class T>
class ConstantExpression final: public ValueExpression<T>
{
    using parent = ValueExpression<T>;

public:

    ConstantExpression(const T& v)
    {
        parent::m_value = v;
    }
    ConstantExpression(const ConstantExpression&) = default;

    ~ConstantExpression() override = default;

    using parent::evaluate;
    void set(const T &) = delete;

    QSharedPointer<Expression<T>> clone() const override
    {
        return DesignPattern::factory<ConstantExpression>(*this);
    }
};
#endif // CONSTANTEXPRESSION_H
