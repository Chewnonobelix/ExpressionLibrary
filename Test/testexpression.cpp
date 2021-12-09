#include "testexpression.h"

TestExpression::TestExpression()
{

}

void TestExpression::iniTestCase()
{
}

void TestExpression::cleanupTestCase()
{

}

void TestExpression::testNaryPush()
{
    QFETCH(QList<bool>, data);
    QFETCH(int, r);

    ConjonctiveForm conj;
    for(auto it: data) {
        ValueExpression<bool> v(it);
        conj.pushBack(v);
    }

    QCOMPARE(conj.count(), r);
}

void TestExpression::testNaryPush_data()
{
    QTest::addColumn<QList<bool>>("data");
    QTest::addColumn<int>("r");

    QTest::newRow("0")<<QList<bool>()<<0;
    QTest::newRow("1")<<QList<bool>{true}<<1;
    QTest::newRow("2")<<QList<bool>{true, true}<<2;
    QTest::newRow("3")<<QList<bool>{true, true, true}<<3;
    QTest::newRow("4")<<QList<bool>{true, true, true, true}<<4;
    QTest::newRow("5")<<QList<bool>{true, true, true, true, true}<<5;
}

void TestExpression::testConjontive()
{
    QFETCH(QList<bool>, data);
    QFETCH(bool, r);

    ConjonctiveForm conj;
    for(auto it: data) {
        ValueExpression<bool> v(it);
        conj.pushBack(v);
    }

    QCOMPARE(conj.evaluate(), r);
}

void TestExpression::testConjontive_data()
{
    QTest::addColumn<QList<bool>>("data");
    QTest::addColumn<bool>("r");

    QTest::newRow("1")<<QList<bool>{true}<<true;
    QTest::newRow("2")<<QList<bool>{true, true}<<true;
    QTest::newRow("3")<<QList<bool>{true, false, true}<<false;
    QTest::newRow("4")<<QList<bool>{true, true, true, true}<<true;
    QTest::newRow("5")<<QList<bool>{true, true, false, true, true}<<false;
}

void TestExpression::testDisjonctive()
{
    QFETCH(QList<bool>, data);
    QFETCH(bool, r);

    DisjonctiveForm conj;
    for(auto it: data) {
        ValueExpression<bool> v(it);
        conj.pushBack(v);
    }

    QCOMPARE(conj.evaluate(), r);
}

void TestExpression::testDisjonctive_data()
{
    QTest::addColumn<QList<bool>>("data");
    QTest::addColumn<bool>("r");

    QTest::newRow("1")<<QList<bool>{true}<<true;
    QTest::newRow("2")<<QList<bool>{true, true}<<true;
    QTest::newRow("3")<<QList<bool>{false, false, false}<<false;
    QTest::newRow("4")<<QList<bool>{true, true, true, true}<<true;
    QTest::newRow("5")<<QList<bool>{true, true, false, true, true}<<true;
}

void TestExpression::testEqual()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(bool, r);

    EqualExpression<int> equal;
    ValueExpression<int> va(a), vb(b);
    equal.setE1(va.clone());
    equal.setE2(vb.clone());

    QCOMPARE(equal.evaluate(), r);
}

void TestExpression::testEqual_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("1=1")<<1<<1<<true;
    QTest::newRow("1=2")<<1<<2<<false;
    QTest::newRow("1=3")<<1<<3<<false;
    QTest::newRow("1=4")<<1<<4<<false;
    QTest::newRow("1=5")<<1<<5<<false;
    QTest::newRow("2=1")<<2<<1<<false;
    QTest::newRow("2=2")<<2<<2<<true;
    QTest::newRow("2=3")<<2<<3<<false;
    QTest::newRow("2=4")<<2<<4<<false;
    QTest::newRow("2=5")<<2<<5<<false;
    QTest::newRow("3=1")<<3<<1<<false;
    QTest::newRow("3=2")<<3<<2<<false;
    QTest::newRow("3=3")<<3<<3<<true;
    QTest::newRow("3=4")<<3<<4<<false;
    QTest::newRow("3=5")<<3<<5<<false;
    QTest::newRow("4=1")<<4<<1<<false;
    QTest::newRow("4=2")<<4<<2<<false;
    QTest::newRow("4=3")<<4<<3<<false;
    QTest::newRow("4=4")<<4<<4<<true;
    QTest::newRow("4=5")<<4<<5<<false;
}

void TestExpression::testInferior()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(bool, r);

    InferiorExpression<int> equal;
    ValueExpression<int> va(a), vb(b);
    equal.setE1(va.clone());
    equal.setE2(vb.clone());

    QCOMPARE(equal.evaluate(), r);
}

void TestExpression::testInferior_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("1<1")<<1<<1<<false;
    QTest::newRow("1<2")<<1<<2<<true;
    QTest::newRow("1<3")<<1<<3<<true;
    QTest::newRow("1<4")<<1<<4<<true;
    QTest::newRow("1<5")<<1<<5<<true;
    QTest::newRow("2<1")<<2<<1<<false;
    QTest::newRow("2<2")<<2<<2<<false;
    QTest::newRow("2<3")<<2<<3<<true;
    QTest::newRow("2<4")<<2<<4<<true;
    QTest::newRow("2<5")<<2<<5<<true;
    QTest::newRow("3<1")<<3<<1<<false;
    QTest::newRow("3<2")<<3<<2<<false;
    QTest::newRow("3<3")<<3<<3<<false;
    QTest::newRow("3<4")<<3<<4<<true;
    QTest::newRow("3<5")<<3<<5<<true;
    QTest::newRow("4<1")<<4<<1<<false;
    QTest::newRow("4<2")<<4<<2<<false;
    QTest::newRow("4<3")<<4<<3<<false;
    QTest::newRow("4<4")<<4<<4<<false;
    QTest::newRow("4<5")<<4<<5<<true;
}

void TestExpression::testSuperior()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(bool, r);

    SuperiorExpression<int> equal;
    ValueExpression<int> va(a), vb(b);
    equal.setE1(va.clone());
    equal.setE2(vb.clone());

    QCOMPARE(equal.evaluate(), r);
}

void TestExpression::testSuperior_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("1>1")<<1<<1<<false;
    QTest::newRow("1>2")<<1<<2<<false;
    QTest::newRow("1>3")<<1<<3<<false;
    QTest::newRow("1>4")<<1<<4<<false;
    QTest::newRow("1>5")<<1<<5<<false;
    QTest::newRow("2>1")<<2<<1<<true;
    QTest::newRow("2>2")<<2<<2<<false;
    QTest::newRow("2>3")<<2<<3<<false;
    QTest::newRow("2>4")<<2<<4<<false;
    QTest::newRow("2>5")<<2<<5<<false;
    QTest::newRow("3>1")<<3<<1<<true;
    QTest::newRow("3>2")<<3<<2<<true;
    QTest::newRow("3>3")<<3<<3<<false;
    QTest::newRow("3>4")<<3<<4<<false;
    QTest::newRow("3>5")<<3<<5<<false;
    QTest::newRow("4>1")<<4<<1<<true;
    QTest::newRow("4>2")<<4<<2<<true;
    QTest::newRow("4>3")<<4<<3<<true;
    QTest::newRow("4>4")<<4<<4<<false;
    QTest::newRow("4>5")<<4<<5<<false;
}

void TestExpression::testAddition()
{
    QFETCH(double, a);
    QFETCH(double, b);
    QFETCH(double, r);

    ValueExpression<double> va(a);
    ValueExpression<double> vb(b);
    AdditionExpression<double> add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testAddition_data()
{
    QTest::addColumn<double>("a");
    QTest::addColumn<double>("b");
    QTest::addColumn<double>("r");

    QTest::newRow("1+1")<<1.0<<1.0<<2.0;
    QTest::newRow("1+2")<<1.0<<2.0<<3.0;
    QTest::newRow("1+3")<<1.0<<3.0<<4.0;
    QTest::newRow("1+4")<<1.0<<4.0<<5.0;
    QTest::newRow("1+5")<<1.0<<5.0<<6.0;
    QTest::newRow("2+1")<<2.0<<1.0<<3.0;
    QTest::newRow("2+2")<<2.0<<2.0<<4.0;
    QTest::newRow("2+3")<<2.0<<3.0<<5.0;
    QTest::newRow("2+4")<<2.0<<4.0<<6.0;
    QTest::newRow("2+5")<<2.0<<5.0<<7.0;
    QTest::newRow("3+1")<<3.0<<1.0<<4.0;
    QTest::newRow("3+2")<<3.0<<2.0<<5.0;
    QTest::newRow("3+3")<<3.0<<3.0<<6.0;
    QTest::newRow("3+4")<<3.0<<4.0<<7.0;
    QTest::newRow("3+5")<<3.0<<5.0<<8.0;
    QTest::newRow("4+1")<<4.0<<1.0<<5.0;
    QTest::newRow("4+2")<<4.0<<2.0<<6.0;
    QTest::newRow("4+3")<<4.0<<3.0<<7.0;
    QTest::newRow("4+4")<<4.0<<4.0<<8.0;
    QTest::newRow("4+5")<<4.0<<5.0<<9.0;
}

void TestExpression::testMultiplication()
{
    QFETCH(double, a);
    QFETCH(double, b);
    QFETCH(double, r);

    ValueExpression<double> va(a);
    ValueExpression<double> vb(b);
    MultiplicationExpression<double> add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testMultiplication_data()
{
    QTest::addColumn<double>("a");
    QTest::addColumn<double>("b");
    QTest::addColumn<double>("r");

    QTest::newRow("1*1")<<1.0<<1.0<<1.0;
    QTest::newRow("1*2")<<1.0<<2.0<<2.0;
    QTest::newRow("1*3")<<1.0<<3.0<<3.0;
    QTest::newRow("1*4")<<1.0<<4.0<<4.0;
    QTest::newRow("1*5")<<1.0<<5.0<<5.0;
    QTest::newRow("2*1")<<2.0<<1.0<<2.0;
    QTest::newRow("2*2")<<2.0<<2.0<<4.0;
    QTest::newRow("2*3")<<2.0<<3.0<<6.0;
    QTest::newRow("2*4")<<2.0<<4.0<<8.0;
    QTest::newRow("2*5")<<2.0<<5.0<<10.0;
    QTest::newRow("3*1")<<3.0<<1.0<<3.0;
    QTest::newRow("3*2")<<3.0<<2.0<<6.0;
    QTest::newRow("3*3")<<3.0<<3.0<<9.0;
    QTest::newRow("3*4")<<3.0<<4.0<<12.0;
    QTest::newRow("3*5")<<3.0<<5.0<<15.0;
    QTest::newRow("4*1")<<4.0<<1.0<<4.0;
    QTest::newRow("4*2")<<4.0<<2.0<<8.0;
    QTest::newRow("4*3")<<4.0<<3.0<<12.0;
    QTest::newRow("4*4")<<4.0<<4.0<<16.0;
    QTest::newRow("4*5")<<4.0<<5.0<<20.0;
}

void TestExpression::testMinus()
{
    QFETCH(double, a);
    QFETCH(double, b);
    QFETCH(double, r);

    ValueExpression<double> va(a);
    ValueExpression<double> vb(b);
    MinusExpression<double> add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testMinus_data()
{
    QTest::addColumn<double>("a");
    QTest::addColumn<double>("b");
    QTest::addColumn<double>("r");

    QTest::newRow("1-1")<<1.0<<1.0<<0.0;
    QTest::newRow("1-2")<<1.0<<2.0<<-1.0;
    QTest::newRow("1-3")<<1.0<<3.0<<-2.0;
    QTest::newRow("1-4")<<1.0<<4.0<<-3.0;
    QTest::newRow("1-5")<<1.0<<5.0<<-4.0;
    QTest::newRow("2-1")<<2.0<<1.0<<1.0;
    QTest::newRow("2-2")<<2.0<<2.0<<0.0;
    QTest::newRow("2-3")<<2.0<<3.0<<-1.0;
    QTest::newRow("2-4")<<2.0<<4.0<<-2.0;
    QTest::newRow("2-5")<<2.0<<5.0<<-3.0;
    QTest::newRow("3-1")<<3.0<<1.0<<2.0;
    QTest::newRow("3-2")<<3.0<<2.0<<1.0;
    QTest::newRow("3-3")<<3.0<<3.0<<0.0;
    QTest::newRow("3-4")<<3.0<<4.0<<-1.0;
    QTest::newRow("3-5")<<3.0<<5.0<<-2.0;
    QTest::newRow("4-1")<<4.0<<1.0<<3.0;
    QTest::newRow("4-2")<<4.0<<2.0<<2.0;
    QTest::newRow("4-3")<<4.0<<3.0<<1.0;
    QTest::newRow("4-4")<<4.0<<4.0<<0.0;
    QTest::newRow("4-5")<<4.0<<5.0<<-1.0;
}

void TestExpression::testDivision()
{
    QFETCH(double, a);
    QFETCH(double, b);
    QFETCH(double, r);

    ValueExpression<double> va(a);
    ValueExpression<double> vb(b);
    DivisionExpression<double> add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testDivision_data()
{
    QTest::addColumn<double>("a");
    QTest::addColumn<double>("b");
    QTest::addColumn<double>("r");

    QTest::newRow("1/1")<<1.0<<1.0<<1.0;
    QTest::newRow("1/2")<<1.0<<2.0<<(1.0/2);
    QTest::newRow("1/3")<<1.0<<3.0<<(1.0/3);
    QTest::newRow("1/4")<<1.0<<4.0<<(1.0/4);
    QTest::newRow("1/5")<<1.0<<5.0<<(1.0/5);
    QTest::newRow("2/1")<<2.0<<1.0<<2.0;
    QTest::newRow("2/2")<<2.0<<2.0<<1.0;
    QTest::newRow("2/3")<<2.0<<3.0<<(2.0/3);
    QTest::newRow("2/4")<<2.0<<4.0<<(2.0/4);
    QTest::newRow("2/5")<<2.0<<5.0<<(2.0/5);
    QTest::newRow("3/1")<<3.0<<1.0<<3.0;
    QTest::newRow("3/2")<<3.0<<2.0<<(3.0/2);
    QTest::newRow("3/3")<<3.0<<3.0<<1.0;
    QTest::newRow("3/4")<<3.0<<4.0<<(3.0/4);
    QTest::newRow("3/5")<<3.0<<5.0<<(3.0/5);
    QTest::newRow("4/1")<<4.0<<1.0<<4.0;
    QTest::newRow("4/2")<<4.0<<2.0<<2.0;
    QTest::newRow("4/3")<<4.0<<3.0<<(4.0/3);
    QTest::newRow("4/4")<<4.0<<4.0<<1.0;
    QTest::newRow("4/5")<<4.0<<5.0<<(4.0/5);
}

void TestExpression::testAnd()
{
    QFETCH(bool, a);
    QFETCH(bool, b);
    QFETCH(bool, r);

    ValueExpression<bool> va(a);
    ValueExpression<bool> vb(b);
    AndExpression add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testAnd_data()
{
    QTest::addColumn<bool>("a");
    QTest::addColumn<bool>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("true&true")<<true<<true<<true;
    QTest::newRow("true&false")<<true<<false<<false;
    QTest::newRow("false&true")<<false<<true<<false;
    QTest::newRow("false&false")<<false<<false<<false;
}

void TestExpression::testOr()
{
    QFETCH(bool, a);
    QFETCH(bool, b);
    QFETCH(bool, r);

    ValueExpression<bool> va(a);
    ValueExpression<bool> vb(b);
    OrExpression add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testOr_data()
{
    QTest::addColumn<bool>("a");
    QTest::addColumn<bool>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("true&true")<<true<<true<<true;
    QTest::newRow("true&false")<<true<<false<<true;
    QTest::newRow("false&true")<<false<<true<<true;
    QTest::newRow("false&false")<<false<<false<<false;
}

void TestExpression::testNot()
{
    QFETCH(bool, a);
    QFETCH(bool, r);

    ValueExpression<bool> va(a);
    NoExpression add;
    add.setE(va.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testNot_data()
{
    QTest::addColumn<bool>("a");
    QTest::addColumn<bool>("r");

    QTest::newRow("!true")<<true<<false;
    QTest::newRow("!false")<<false<<true;
}

void TestExpression::testEquivalent()
{
    QFETCH(bool, a);
    QFETCH(bool, b);
    QFETCH(bool, r);

    ValueExpression<bool> va(a);
    ValueExpression<bool> vb(b);
    EquivalentExpression add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testEquivalent_data()
{
    QTest::addColumn<bool>("a");
    QTest::addColumn<bool>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("true&true")<<true<<true<<true;
    QTest::newRow("true&false")<<true<<false<<false;
    QTest::newRow("false&true")<<false<<true<<false;
    QTest::newRow("false&false")<<false<<false<<true;
}

void TestExpression::testImplies()
{
    QFETCH(bool, a);
    QFETCH(bool, b);
    QFETCH(bool, r);

    ValueExpression<bool> va(a);
    ValueExpression<bool> vb(b);
    ImpliesExpression add;
    add.setE1(va.clone());
    add.setE2(vb.clone());

    auto res = add.evaluate();
    QCOMPARE(res, r);
}

void TestExpression::testImplies_data()
{
    QTest::addColumn<bool>("a");
    QTest::addColumn<bool>("b");
    QTest::addColumn<bool>("r");

    QTest::newRow("true&true")<<true<<true<<true;
    QTest::newRow("true&false")<<true<<false<<false;
    QTest::newRow("false&true")<<false<<true<<true;
    QTest::newRow("false&false")<<false<<false<<true;
}
