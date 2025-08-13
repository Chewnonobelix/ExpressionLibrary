
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Comparaison/equalexpression.h"
#include "Core/constantexpression.h"

class EqualExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_table_int()
    {
        struct C{int a,b;bool expect;};
        QList<C> cases = {{1,1,true},{1,2,false},{-5,-5,true},{0,5,false}};
        for (const auto &c : cases){
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(c.a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(c.b);
            EqualExpression<int> eq;
            eq.setE1(e1);
            eq.setE2(e2);
            QCOMPARE(eq.evaluate(), c.expect);
        }
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<150;i++){
            int a = int(rng->bounded(-100,100));
            int b = int(rng->bounded(-100,100));
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            EqualExpression<int> eq;
            eq.setE1(e1);
            eq.setE2(e2);
            QCOMPARE(eq.evaluate(), a == b);
        }
    }
};

#include <tst_equalexpression.moc>
