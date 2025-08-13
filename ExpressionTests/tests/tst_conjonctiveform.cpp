
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/conjonctiveform.h"
#include "Core/constantexpression.h"

class ConjonctiveFormTest : public QObject
{
    Q_OBJECT
private slots:
    void test_all_true()
    {
        ConjonctiveForm cf;
        cf.pushBack(QSharedPointer<ConstantExpression<bool>>::create(true));
        cf.pushBack(QSharedPointer<ConstantExpression<bool>>::create(true));
        QVERIFY(cf.evaluate());
    }

    void test_contains_false()
    {
        ConjonctiveForm cf;
        cf.pushBack(QSharedPointer<ConstantExpression<bool>>::create(true));
        cf.pushBack(QSharedPointer<ConstantExpression<bool>>::create(false));
        QVERIFY(!cf.evaluate());
    }

    void test_random_lists()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<60;i++){
            ConjonctiveForm cf;
            bool expected = true;
            int n = int(rng->bounded(1,8));
            for (int j=0;j<n;j++){
                bool val = rng->bounded(0,2);
                cf.pushBack(QSharedPointer<ConstantExpression<bool>>::create(val));
                expected = expected && val;
            }
            QCOMPARE(cf.evaluate(), expected);
        }
    }
};

#include <tst_conjonctiveform.moc>
