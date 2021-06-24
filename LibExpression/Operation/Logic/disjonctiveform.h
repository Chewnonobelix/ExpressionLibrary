#ifndef DISJONCTIVEFORM_H
#define DISJONCTIVEFORM_H

#include "Core/expression_global.h"
#include "Core/naryexpression.h"
#include "designpattern.h"

class EXPRESSIONSHARED_EXPORT DisjonctiveForm: public NaryExpression<bool, bool>
{
public:
    DisjonctiveForm() = default;
    DisjonctiveForm(const DisjonctiveForm&) = default;
    ~DisjonctiveForm() = default;
    
    bool evaluate() const;
    QSharedPointer<Expression<bool, bool>> clone() const;
    
};

#endif // DISJONCTIVEFORM_H
