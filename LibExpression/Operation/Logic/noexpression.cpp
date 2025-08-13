#include "noexpression.h"

bool NoExpression::evaluate() const
{
    return !e()->evaluate();
}

QSharedPointer<Expression<bool> > NoExpression::clone() const
{
    return QSharedPointer<NoExpression>::create(*this);
}
