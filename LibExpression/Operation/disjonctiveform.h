#ifndef DISJONCTIVEFORM_H
#define DISJONCTIVEFORM_H

#include "expression_global.h"
#include "naryexpression.h"
#include "designpattern.h"

class EXPRESSIONSHARED_EXPORT DisjonctiveForm: public NaryExpression<bool>
{
public:
    DisjonctiveForm() = default;
    DisjonctiveForm(const DisjonctiveForm&) = default;
    ~DisjonctiveForm() = default;
    
    bool evaluate() const;
    QSharedPointer<Expression<bool>> clone() const;
    
};

#endif // DISJONCTIVEFORM_H
