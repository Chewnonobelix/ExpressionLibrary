
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Core/valueexpression.h"
#include "Core/constantexpression.h"

class ValueExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_int_and_double()
    {
        ValueExpression<int> vi(7);
        QCOMPARE(vi.evaluate(), 7);
        vi.set(11);
        QCOMPARE(vi.evaluate(), 11);

        ValueExpression<double> vd(1.5);
        QCOMPARE(vd.evaluate(), 1.5);
        vd.set(2.25);
        QCOMPARE(vd.evaluate(), 2.25);
    }

    void test_random_ints()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<100;i++){
            int v = int(rng->bounded(0,10000));
            ValueExpression<int> vi(v);
            QCOMPARE(vi.evaluate(), v);
        }
    }
};

#include <tst_valueexpression.moc>

