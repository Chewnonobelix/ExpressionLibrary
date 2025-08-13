
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/noexpression.h"
#include "Core/constantexpression.h"

class NoExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_truth_table()
    {
        auto eTrue = QSharedPointer<ConstantExpression<bool>>::create(true);
        NoExpression n1;
        n1.setE(eTrue);
        QCOMPARE(n1.evaluate(), false);

        auto eFalse = QSharedPointer<ConstantExpression<bool>>::create(false);
        NoExpression n2;
        n2.setE(eFalse);
        QCOMPARE(n2.evaluate(), true);
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<80;i++){
            bool v = rng->bounded(0,2);
            NoExpression ne;
            ne.setE(QSharedPointer<ConstantExpression<bool>>::create(v));
            QCOMPARE(ne.evaluate(), !v);
        }
    }
};

#include <tst_noexpression.moc>

