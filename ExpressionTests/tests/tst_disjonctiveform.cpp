
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Operation/Logic/disjonctiveform.h"
#include "Core/constantexpression.h"

class DisjonctiveFormTest : public QObject
{
    Q_OBJECT
private slots:
    void test_all_false()
    {
        DisjonctiveForm df;
        df.pushBack(QSharedPointer<ConstantExpression<bool>>::create(false));
        df.pushBack(QSharedPointer<ConstantExpression<bool>>::create(false));
        QVERIFY(!df.evaluate());
    }

    void test_contains_true()
    {
        DisjonctiveForm df;
        df.pushBack(QSharedPointer<ConstantExpression<bool>>::create(false));
        df.pushBack(QSharedPointer<ConstantExpression<bool>>::create(true));
        QVERIFY(df.evaluate());
    }

    void test_random_lists()
    {
        auto rng = QRandomGenerator::global();
        for (int i=0;i<60;i++){
            DisjonctiveForm df;
            bool expected = false;
            int n = int(rng->bounded(1,8));
            for (int j=0;j<n;j++){
                bool val = rng->bounded(0,2);
                df.pushBack(QSharedPointer<ConstantExpression<bool>>::create(val));
                expected = expected || val;
            }
            QCOMPARE(df.evaluate(), expected);
        }
    }
};

#include <tst_disjonctiveform.moc>
