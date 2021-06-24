#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include "expression.h"

template <class T, class R>
class NaryExpression: public Expression<T, R>
{
protected:
    QList<QSharedPointer<Expression<T, R>>> m_list;

public:
    NaryExpression<T, R>() = default;
    NaryExpression<T, R>(const NaryExpression<T, R>&) = default;
    ~NaryExpression() override = default;   
    
    inline void clear() {m_list.clear();}
    inline int count() const {return m_list.count();}
    
    void pushBack(const Expression<T, R>& e)
    {
        m_list<<e.clone();
    }
    
    void pushBack(QSharedPointer<Expression<T, R>>e)
    {
        m_list<<e;
    }
};

#endif // NARYEXPRESSION_H
