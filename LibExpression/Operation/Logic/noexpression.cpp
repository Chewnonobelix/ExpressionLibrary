#include "noexpression.h"

bool NoExpression::evaluate() const
{
    return !e()->evaluate();
}

QSharedPointer<Expression<bool, bool> > NoExpression::clone() const
{
    return DesignPattern::factory<NoExpression>(*this);
}
