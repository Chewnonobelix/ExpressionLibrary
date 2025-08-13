#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QSharedPointer>

template <class T> class Expression {
private:
public:
	Expression() = default;

	Expression(const Expression<T> &) = default;

	virtual ~Expression() = default;

	QSharedPointer<Expression<T>>
	operator=(const QSharedPointer<Expression<T>> &) {
		return QSharedPointer<Expression<T>>::create(*this);
	}

	virtual T evaluate() const = 0;
	virtual QSharedPointer<Expression<T>> clone() const = 0;
};

#endif // EXPRESSION_H
