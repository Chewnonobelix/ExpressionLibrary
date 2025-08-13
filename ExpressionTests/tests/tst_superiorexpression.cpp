
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Comparaison/superiorexpression.h"
#include "Core/constantexpression.h"

class SuperiorExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_table_int()
    {
        struct C{int a,b;bool expect;};
        QList<C> cases = {{3,2,true},{2,3,false},{0,0,false},{5,-1,true}};
        for (const auto &c : cases){
            auto e1 = QSharedPointer<ConstantExpression<int>>::create(c.a);
            auto e2 = QSharedPointer<ConstantExpression<int>>::create(c.b);
            SuperiorExpression<int> sup;
            sup.setE1(e1);
            sup.setE2(e2);
            QCOMPARE(sup.evaluate(), c.expect);
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
            SuperiorExpression<int> sup;
            sup.setE1(e1);
            sup.setE2(e2);
            QCOMPARE(sup.evaluate(), a > b);
        }
    }
};

#include <tst_superiorexpression.moc>

