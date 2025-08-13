
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/impliedexpression.h"
#include "Core/constantexpression.h"

class ImpliesExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_truth_table()
    {
        // implication: A -> B is (!A) || B
        struct Case{ bool a; bool b; bool expected; };
        QList<Case> table = {
            {false,false,true},
            {false,true,true},
            {true,false,false},
            {true,true,true}
        };
        for (const auto &c : table){
            ImpliesExpression impl;
            impl.setE1(QSharedPointer<ConstantExpression<bool>>::create(c.a));
            impl.setE2(QSharedPointer<ConstantExpression<bool>>::create(c.b));
            QCOMPARE(impl.evaluate(), c.expected);
        }
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<80;i++){
            bool a = rng->bounded(0,2);
            bool b = rng->bounded(0,2);
            ImpliesExpression impl;
            impl.setE1(QSharedPointer<ConstantExpression<bool>>::create(a));
            impl.setE2(QSharedPointer<ConstantExpression<bool>>::create(b));
            QCOMPARE(impl.evaluate(), (!a) || b);
        }
    }
};

#include <tst_impliesexpression.moc>

