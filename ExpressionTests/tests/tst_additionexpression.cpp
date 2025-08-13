
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Arithmetic/additionexpression.h"
#include "Core/constantexpression.h"

class AdditionExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_basic_int()
    {
        auto e1 = QSharedPointer<ConstantExpression<int>>::create(3);
        auto e2 = QSharedPointer<ConstantExpression<int>>::create(4);
        AdditionExpression<int> add;
        add.setE1(e1);
        add.setE2(e2);
        QCOMPARE(add.evaluate(), 7);
    }

    void test_basic_double()
    {
        auto e1 = QSharedPointer<ConstantExpression<double>>::create(1.5);
        auto e2 = QSharedPointer<ConstantExpression<double>>::create(2.5);
        AdditionExpression<double> add;
        add.setE1(e1);
        add.setE2(e2);
        QCOMPARE(add.evaluate(), 4.0);
    }

    void test_random_int()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<200;i++){
            int a = int(rng->bounded(0,1000));
            int b = int(rng->bounded(0,1000));
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            AdditionExpression<int> add;
            add.setE1(e1);
            add.setE2(e2);
            QCOMPARE(add.evaluate(), a + b);
        }
    }

    void test_clone()
    {
        auto e1 = QSharedPointer<ConstantExpression<int>>::create(42);
        auto e2 = QSharedPointer<ConstantExpression<int>>::create(1);
        AdditionExpression<int> add;
        add.setE1(e1);
        add.setE2(e2);
        auto clone = add.clone();
        QVERIFY(!clone.isNull());
        QCOMPARE(clone->evaluate(), 43);
    }
};

#include <tst_additionexpression.moc>

