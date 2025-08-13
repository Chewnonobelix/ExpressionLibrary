
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Arithmetic//divisionexpression.h"
#include "Core/constantexpression.h"

class DivisionExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_basic()
    {
        auto e1 = QSharedPointer<ConstantExpression<int>>::create(10);
        auto e2 = QSharedPointer<ConstantExpression<int>>::create(2);
        DivisionExpression<int> div;
        div.setE1(e1);
        div.setE2(e2);
        QCOMPARE(div.evaluate(), 5);
    }

    void test_random_nonzero_divisor()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<150;i++){
            int a = int(rng->bounded(-1000,1000));
            int b = int(rng->bounded(-1000,1000));
            if (b == 0) b = 1;
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            DivisionExpression<int> div;
            div.setE1(e1);
            div.setE2(e2);
            QCOMPARE(div.evaluate(), a / b);
        }
    }
};

#include <tst_divisionexpression.moc>

