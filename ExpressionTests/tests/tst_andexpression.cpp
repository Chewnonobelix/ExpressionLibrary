
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/andexpression.h"
#include "Core/constantexpression.h"

class AndExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_truth_table()
    {
        struct Case { bool a; bool b; bool expected; };
        QList<Case> table = {
            {false, false, false},
            {false, true,  false},
            {true,  false, false},
            {true,  true,  true}
        };

        for (const auto &c : table) {
            auto e1 = QSharedPointer<ConstantExpression<bool>>::create(c.a);
            auto e2 = QSharedPointer<ConstantExpression<bool>>::create(c.b);
            AndExpression andExpr;
            andExpr.setE1(e1);
            andExpr.setE2(e2);
            QCOMPARE(andExpr.evaluate(), c.expected);
        }
    }

    void test_random_cases()
    {
        auto rng = QRandomGenerator::global();
        for (int i = 0; i < 100; ++i) {
            bool a = rng->bounded(0,2);
            bool b = rng->bounded(0,2);
            auto e1 = QSharedPointer<ConstantExpression<bool>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<bool>>::create(b);
            AndExpression expr;
            expr.setE1(e1);
            expr.setE2(e2);
            QCOMPARE(expr.evaluate(), a && b);
        }
    }
};

#include <tst_andexpression.moc>

