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

#include "Operation/Comparaison/equalexpression.h"
#include "Operation/Comparaison/superiorexpression.h"
#include "Operation/Comparaison/inferiorexpression.h"

class TestExpression : public QObject
{
    Q_OBJECT
public:
    TestExpression();

private:

private slots:
    void iniTestCase();
    void cleanupTestCase();

    void testAddition();
    void testAddition_data();
    void testMinus();
    void testMinus_data();
    void testMultiplication();
    void testMultiplication_data();
    void testDivision();
    void testDivision_data();

    void testAnd();
    void testAnd_data();
    void testOr();
    void testOr_data();
    void testNot();
    void testNot_data();
    void testEquivalent();
    void testEquivalent_data();
    void testImplies();
    void testImplies_data();
    
    void testNaryPush();
    void testNaryPush_data();
    void testConjontive();
    void testConjontive_data();
    void testDisjonctive();
    void testDisjonctive_data();

    void testEqual();
    void testEqual_data();
    void testInferior();
    void testInferior_data();
    void testSuperior();
    void testSuperior_data();
};

#endif // TESTEXPRESSION_H
