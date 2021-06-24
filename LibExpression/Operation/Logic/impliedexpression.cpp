#include "impliedexpression.h"

bool ImpliesExpression::evaluate() const
{
    return !e1()->evaluate() || e2()->evaluate();
}

QSharedPointer<Expression<bool> > ImpliesExpression::clone() const
{
    return DesignPattern::factory<ImpliesExpression>(*this);
}
