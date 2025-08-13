
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/orexpression.h"
#include "Core/constantexpression.h"

class OrExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_truth_table()
    {
        struct Case { bool a; bool b; bool expected; };
        QList<Case> table = {
            {false, false, false},
            {false, true,  true},
            {true,  false, true},
            {true,  true,  true}
        };

        for (const auto &c : table) {
            auto e1 = QSharedPointer<ConstantExpression<bool>>::create(c.a);
            auto e2 = QSharedPointer<ConstantExpression<bool>>::create(c.b);
            OrExpression orExpr;
            orExpr.setE1(e1);
            orExpr.setE2(e2);
            QCOMPARE(orExpr.evaluate(), c.expected);
        }
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<100;i++){
            bool a = rng->bounded(0,2);
            bool b = rng->bounded(0,2);
            auto e1 = QSharedPointer<ConstantExpression<bool>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<bool>>::create(b);
            OrExpression orExpr;
            orExpr.setE1(e1);
            orExpr.setE2(e2);
            QCOMPARE(orExpr.evaluate(), a || b);
        }
    }
};

#include <tst_orexpression.moc>

