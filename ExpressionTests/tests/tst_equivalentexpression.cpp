
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/equivalentexpression.h"
#include "Core/constantexpression.h"

class EquivalentExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_table()
    {
        struct Case { bool a; bool b; bool expected; };
        QList<Case> table = {
            {false,false,true},
            {false,true,false},
            {true,false,false},
            {true,true,true}
        };
        for (const auto &c : table){
            EquivalentExpression eq;
            eq.setE1(QSharedPointer<ConstantExpression<bool>>::create(c.a));
            eq.setE2(QSharedPointer<ConstantExpression<bool>>::create(c.b));
            QCOMPARE(eq.evaluate(), c.expected);
        }
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<80;i++){
            bool a = rng->bounded(0,2);
            bool b = rng->bounded(0,2);
            EquivalentExpression eq;
            eq.setE1(QSharedPointer<ConstantExpression<bool>>::create(a));
            eq.setE2(QSharedPointer<ConstantExpression<bool>>::create(b));
            QCOMPARE(eq.evaluate(), (a == b));
        }
    }
};

#include <tst_equivalentexpression.moc>

