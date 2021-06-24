#ifndef TESTEXPRESSION_H
#define TESTEXPRESSION_H

#include <QObject>
#include <QTest>

#include "Core/valueexpression.h"
#include "Operation/Arithmetic/additionexpression.h"
#include "Operation/Arithmetic/minusexpression.h"
#include "Operation/Arithmetic/multiplicationexpression.h"
#include "Operation/Arithmetic/divisionexpression.h"

#include "Operation/Logic/andexpression.h"
#include "Operation/Logic/orexpression.h"
#include "Operation/Logic/noexpression.h"
#include "Operation/Logic/impliedexpression.h"
#include "Operation/Logic/equivalentexpression.h"
#include "Operation/Logic/conjonctiveform.h"
#include "Operation/Logic/disjonctiveform.h"

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

    ConjonctiveForm m_conj;
    DisjonctiveForm m_dis;
    
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
    
    void testNaryPush();
    void testConjontive();
    void testDisjonctive();
};

#endif // TESTEXPRESSION_H
