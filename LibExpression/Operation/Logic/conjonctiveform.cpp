#include "conjonctiveform.h"

bool ConjonctiveForm::evaluate() const
{
    bool ret = true;
    
    for(auto it: m_list)
        ret &= it->evaluate();
    
    return ret;
}

QSharedPointer<Expression<bool, bool>> ConjonctiveForm::clone() const
{
     return DesignPattern::factory<ConjonctiveForm>(*this);    
}
