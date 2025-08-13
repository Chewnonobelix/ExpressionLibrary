
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Arithmetic//minusexpression.h"
#include "Core/constantexpression.h"

class MinusExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_basic_int()
    {
        auto e1 = QSharedPointer<ConstantExpression<int>>::create(10);
        auto e2 = QSharedPointer<ConstantExpression<int>>::create(4);
        MinusExpression<int> sub;
        sub.setE1(e1);
        sub.setE2(e2);
        QCOMPARE(sub.evaluate(), 6);
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<150;i++){
            int a = int(rng->bounded(-500,500));
            int b = int(rng->bounded(-500,500));
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            MinusExpression<int> sub;
            sub.setE1(e1);
            sub.setE2(e2);
            QCOMPARE(sub.evaluate(), a - b);
        }
    }
};

#include <tst_minusexpression.moc>
