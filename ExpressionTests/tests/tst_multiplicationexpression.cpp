
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Arithmetic//multiplicationexpression.h"
#include "Core/constantexpression.h"

class MultiplicationExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_basic()
    {
        auto e1 = QSharedPointer<ConstantExpression<int>>::create(3);
        auto e2 = QSharedPointer<ConstantExpression<int>>::create(5);
        MultiplicationExpression<int> mul;
        mul.setE1(e1);
        mul.setE2(e2);
        QCOMPARE(mul.evaluate(), 15);
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<120;i++){
            int a = int(rng->bounded(-100,100));
            int b = int(rng->bounded(-100,100));
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            MultiplicationExpression<int> mul;
            mul.setE1(e1);
            mul.setE2(e2);
            QCOMPARE(mul.evaluate(), a * b);
        }
    }
};

#include <tst_multiplicationexpression.moc>

