#include "testexpression.h"

TestExpression::TestExpression()
{

}

void TestExpression::iniTestCase()
{
    m_v1.set(12.1);
    m_v2.set(15.7);

    m_add.setE1(m_v1.clone());
    m_add.setE2(m_v2.clone());
    m_minus.setE1(m_v1.clone());
    m_minus.setE2(m_v2.clone());
    m_mult.setE1(m_v1.clone());
    m_mult.setE2(m_v2.clone());
    m_div.setE1(m_v1.clone());
    m_div.setE2(m_v2.clone());

    m_b1.set(true);
    m_b2.set(false);
    m_b3.set(true);
    m_b4.set(false);

    m_and1.setE1(m_b1.clone());
    m_and1.setE2(m_b3.clone());
    m_and2.setE1(m_b1.clone());
    m_and2.setE2(m_b4.clone());
    m_and3.setE1(m_b2.clone());
    m_and3.setE2(m_b3.clone());
    m_and4.setE1(m_b2.clone());
    m_and4.setE2(m_b4.clone());

     m_no1.setE(m_b1.clone());
     m_no2.setE(m_b2.clone());

     m_or1.setE1(m_b1.clone());
     m_or1.setE2(m_b3.clone());
     m_or2.setE1(m_b1.clone());
     m_or2.setE2(m_b4.clone());
     m_or3.setE1(m_b2.clone());
     m_or3.setE2(m_b3.clone());
     m_or4.setE1(m_b2.clone());
     m_or4.setE2(m_b4.clone());

     m_imp1.setE1(m_b1.clone());
     m_imp1.setE2(m_b3.clone());
     m_imp2.setE1(m_b1.clone());
     m_imp2.setE2(m_b4.clone());
     m_imp3.setE1(m_b2.clone());
     m_imp3.setE2(m_b3.clone());
     m_imp4.setE1(m_b2.clone());
     m_imp4.setE2(m_b4.clone());

     m_eq1.setE1(m_b1.clone());
     m_eq1.setE2(m_b3.clone());
     m_eq2.setE1(m_b1.clone());
     m_eq2.setE2(m_b4.clone());
     m_eq3.setE1(m_b2.clone());
     m_eq3.setE2(m_b3.clone());
     m_eq4.setE1(m_b2.clone());
     m_eq4.setE2(m_b4.clone());

}

void TestExpression::cleanupTestCase()
{

}

void TestExpression::testAddition()
{
    QCOMPARE(m_add.evaluate(), (12.1+15.7));
}

void TestExpression::testMinus()
{
    QCOMPARE(m_minus.evaluate(), (12.1-15.7));
}

void TestExpression::testMultiplication()
{
    QCOMPARE(m_mult.evaluate(), (12.1*15.7));
}

void TestExpression::testDivision()
{
    QCOMPARE(m_div.evaluate(), (12.1/15.7));
}


void TestExpression::testAnd()
{
    QCOMPARE(m_and1.evaluate(), true);
    QCOMPARE(m_and2.evaluate(), false);
    QCOMPARE(m_and3.evaluate(), false);
    QCOMPARE(m_and4.evaluate(), false);
}

void TestExpression::testOr()
{
    QCOMPARE(m_or1.evaluate(), true);
    QCOMPARE(m_or2.evaluate(), true);
    QCOMPARE(m_or3.evaluate(), true);
    QCOMPARE(m_or4.evaluate(), false);
}
void TestExpression::testNot()
{
    QCOMPARE(m_no1.evaluate(), false);
    QCOMPARE(m_no2.evaluate(), true);
}

void TestExpression::testEquivalent()
{
    QCOMPARE(m_eq1.evaluate(), true);
    QCOMPARE(m_eq2.evaluate(), false);
    QCOMPARE(m_eq3.evaluate(), false);
    QCOMPARE(m_eq4.evaluate(), true);
}

void TestExpression::testImplies()
{
    QCOMPARE(m_imp1.evaluate(), true);
    QCOMPARE(m_imp2.evaluate(), false);
    QCOMPARE(m_imp3.evaluate(), true);
    QCOMPARE(m_imp4.evaluate(), true);
}
