#ifndef CONJONCTIVEFORM_H
#define CONJONCTIVEFORM_H

#include <Core/expression_global.h>
#include "Core/naryexpression.h"
#include "designpattern.h"

class EXPRESSIONSHARED_EXPORT ConjonctiveForm: public NaryExpression<bool, bool>
{
public:
    ConjonctiveForm() = default;
    ConjonctiveForm(const ConjonctiveForm&) = default;
    ~ConjonctiveForm() = default;
    
    bool evaluate() const;
    QSharedPointer<Expression<bool, bool>> clone() const;
    
};

#endif // CONJONCTIVEFORM_H
