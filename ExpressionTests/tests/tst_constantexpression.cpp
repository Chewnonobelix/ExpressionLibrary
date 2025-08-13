
#include <QtTest/QtTest>
#include <QSharedPointer>
#include "Core/constantexpression.h"

class ConstantExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void test_basic()
    {
        ConstantExpression<int> c(42);
        QCOMPARE(c.evaluate(), 42);
        auto clone = c.clone();
        QVERIFY(!clone.isNull());
        QCOMPARE(clone->evaluate(), 42);
    }

    void test_types()
    {
        ConstantExpression<double> cd(3.14159);
        QCOMPARE(cd.evaluate(), 3.14159);

        ConstantExpression<bool> cb(true);
        QCOMPARE(cb.evaluate(), true);
    }
};

#include <tst_constantexpression.moc>
