#include <QCoreApplication>
#include <QTest>

// Forward declarations of test classes
#include "tests/tst_valueexpression.cpp"
#include "tests/tst_constantexpression.cpp"
#include "tests/tst_additionexpression.cpp"
#include "tests/tst_minusexpression.cpp"
#include "tests/tst_multiplicationexpression.cpp"
#include "tests/tst_divisionexpression.cpp"
#include "tests/tst_equalexpression.cpp"
#include "tests/tst_inferiorexpression.cpp"
#include "tests/tst_superiorexpression.cpp"
#include "tests/tst_andexpression.cpp"
#include "tests/tst_orexpression.cpp"
#include "tests/tst_noexpression.cpp"
#include "tests/tst_equivalentexpression.cpp"
#include "tests/tst_impliesexpression.cpp"
#include "tests/tst_conjonctiveform.cpp"
#include "tests/tst_disjonctiveform.cpp"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    int status = 0;
    // Each test class is defined in the included .cpp files, we instantiate and run them.
    status |= QTest::qExec(new ValueExpressionTest, argc, argv);
    status |= QTest::qExec(new ConstantExpressionTest, argc, argv);
    status |= QTest::qExec(new AdditionExpressionTest, argc, argv);
    status |= QTest::qExec(new MinusExpressionTest, argc, argv);
    status |= QTest::qExec(new MultiplicationExpressionTest, argc, argv);
    status |= QTest::qExec(new DivisionExpressionTest, argc, argv);
    status |= QTest::qExec(new EqualExpressionTest, argc, argv);
    status |= QTest::qExec(new InferiorExpressionTest, argc, argv);
    status |= QTest::qExec(new SuperiorExpressionTest, argc, argv);
    status |= QTest::qExec(new AndExpressionTest, argc, argv);
    status |= QTest::qExec(new OrExpressionTest, argc, argv);
    status |= QTest::qExec(new NoExpressionTest, argc, argv);
    status |= QTest::qExec(new EquivalentExpressionTest, argc, argv);
    status |= QTest::qExec(new ImpliesExpressionTest, argc, argv);
    status |= QTest::qExec(new ConjonctiveFormTest, argc, argv);
    status |= QTest::qExec(new DisjonctiveFormTest, argc, argv);

    return status;
}
