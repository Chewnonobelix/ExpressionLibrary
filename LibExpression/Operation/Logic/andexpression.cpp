#include "andexpression.h"

bool AndExpression::evaluate() const
{
    return e1()->evaluate() && e2()->evaluate();
}

QSharedPointer<Expression<bool> > AndExpression::clone() const
{
    return DesignPattern::factory<AndExpression>(*this);
}
