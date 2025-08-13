
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Comparaison/inferiorexpression.h"
#include "Core/constantexpression.h"

class InferiorExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_table_int()
    {
        struct C{int a,b;bool expect;};
        QList<C> cases = {{1,2,true},{2,1,false},{0,0,false},{-1,1,true}};
        for (const auto &c : cases){
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(c.a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(c.b);
            InferiorExpression<int> inf;
            inf.setE1(e1);
            inf.setE2(e2);
            QCOMPARE(inf.evaluate(), c.expect);
        }
    }

    void test_random()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<150;i++){
            int a = int(rng->bounded(-200,200));
            int b = int(rng->bounded(-200,200));
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(b);
            InferiorExpression<int> inf;
            inf.setE1(e1);
            inf.setE2(e2);
            QCOMPARE(inf.evaluate(), a < b);
        }
    }
};

#include <tst_inferiorexpression.moc>

