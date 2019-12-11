#include <QApplication>
#include <QTest>

#include "testexpression.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    int status = 0;
    TestExpression tex;
    status |= QTest::qExec(&tex, argc, argv);


    return status;
}
