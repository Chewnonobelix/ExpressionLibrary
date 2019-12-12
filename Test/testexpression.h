#ifndef TESTEXPRESSION_H
#define TESTEXPRESSION_H

#include <QObject>
#include <QTest>

#include "valueexpression.h"
#include "additionexpression.h"
#include "minusexpression.h"
#include "multiplicationexpression.h"
#include "divisionexpression.h"

#include "andexpression.h"
#include "orexpression.h"
#include "noexpression.h"
#include "impliedexpression.h"
#include "equivalentexpression.h"

class TestExpression : public QObject
{
    Q_OBJECT
public:
    TestExpression();

private:
    AdditionExpression<double> m_add;
    MinusExpression<double> m_minus;
    MultiplicationExpression<double> m_mult;
    DivisionExpression<double> m_div;
    ValueExpression<double> m_v1, m_v2;

    ValueExpression<bool> m_b1, m_b2, m_b3, m_b4;
    AndExpression m_and1, m_and2, m_and3, m_and4;
    OrExpression m_or1, m_or2, m_or3, m_or4;
    ImpliesExpression m_imp1, m_imp2, m_imp3, m_imp4;
    EquivalentExpression m_eq1, m_eq2, m_eq3, m_eq4;

    NoExpression m_no1, m_no2;

private slots:
    void iniTestCase();
    void cleanupTestCase();

    void testAddition();
    void testMinus();
    void testMultiplication();
    void testDivision();

    void testAnd();
    void testOr();
    void testNot();
    void testEquivalent();
    void testImplies();
};

#endif // TESTEXPRESSION_H