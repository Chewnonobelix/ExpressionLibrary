#ifndef CONJONCTIVEFORM_H
#define CONJONCTIVEFORM_H

#include "expression_global.h"
#include "naryexpression.h"
#include "designpattern.h"

class EXPRESSIONSHARED_EXPORT ConjonctiveForm: public NaryExpression<bool>
{
public:
    ConjonctiveForm() = default;
    ConjonctiveForm(const ConjonctiveForm&) = default;
    ~ConjonctiveForm() = default;
    
    bool evaluate() const;
    QSharedPointer<Expression<bool>> clone() const;
    
};

#endif // CONJONCTIVEFORM_H
