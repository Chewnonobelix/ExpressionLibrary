#include "orexpression.h"

bool OrExpression::evaluate() const
{
    return e1()->evaluate() || e2()->evaluate();
}

QSharedPointer<Expression<bool> > OrExpression::clone() const
{
    return QSharedPointer<OrExpression>::create(*this);
}
