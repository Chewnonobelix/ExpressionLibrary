#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include "expression.h"

template<class T>
class NaryExpression: public Expression<T>
{
protected:
    QList<QSharedPointer<Expression<T>>> m_list;

public:
    NaryExpression() = default;
    NaryExpression(const NaryExpression<T>&) = default;
    ~NaryExpression() override = default;   
    
    inline void clear() {m_list.clear();}
    inline int count() const {return m_list.count();}
    
    void pushBack(const Expression<T>& e)
    {
        m_list<<e.clone();
    }
    
    void pushBack(QSharedPointer<Expression<T>>e)
    {
        m_list<<e;
    }
};

#endif // NARYEXPRESSION_H
