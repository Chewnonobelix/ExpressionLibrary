#include "equivalentexpression.h"

bool EquivalentExpression::evaluate() const
{
    return (e1()->evaluate() && e2()->evaluate()) || !(e1()->evaluate() || e2()->evaluate());
}

QSharedPointer<Expression<bool> > EquivalentExpression::clone() const
{
    return DesignPattern::factory<EquivalentExpression>(*this);
}
