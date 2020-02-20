#include "disjonctiveform.h"

bool DisjonctiveForm::evaluate() const
{
    bool ret = false;
    
    for(auto it: m_list)
        ret |= it->evaluate();
    
    return ret;
}

QSharedPointer<Expression<bool>> DisjonctiveForm::clone() const
{
     return DesignPattern::factory<DisjonctiveForm>(*this);    
}
