#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "designpattern.h"
#include <QSharedPointer>

template <class T, class R>
class Expression {
private:
public:
	Expression() = default;

    Expression(const Expression<T,R> &) = default;

	virtual ~Expression() = default;

    QSharedPointer<Expression<T,R>>
    operator=(const QSharedPointer<Expression<T,R>> &) {
        return QSharedPointer<Expression<T,R>>::create(*this);
	}

    virtual R evaluate() const = 0;
    virtual QSharedPointer<Expression<T,R>> clone() const = 0;
};

#endif // EXPRESSION_H
