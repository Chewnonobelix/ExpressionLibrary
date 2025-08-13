QT += core testlib
CONFIG += console c++17 testcase
TEMPLATE = app
TARGET = ExpressionTests

SOURCES += main.cpp \
    tests/tst_valueexpression.cpp \
    tests/tst_constantexpression.cpp \
    tests/tst_additionexpression.cpp \
    tests/tst_minusexpression.cpp \
    tests/tst_multiplicationexpression.cpp \
    tests/tst_divisionexpression.cpp \
    tests/tst_equalexpression.cpp \
    tests/tst_inferiorexpression.cpp \
    tests/tst_superiorexpression.cpp \
    tests/tst_andexpression.cpp \
    tests/tst_orexpression.cpp \
    tests/tst_noexpression.cpp \
    tests/tst_equivalentexpression.cpp \
    tests/tst_impliesexpression.cpp \
    tests/tst_conjonctiveform.cpp \
    tests/tst_disjonctiveform.cpp

# Add include path if needed:
INCLUDEPATH += $$PWD/../LibExpression
LIBS += -L$$OUT_PWD/../LibExpression -lLibExpression
