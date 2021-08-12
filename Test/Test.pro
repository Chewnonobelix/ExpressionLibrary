QT += testlib
QT += gui core widgets network xml testlib
CONFIG += qt warn_on depend_includepath testcase c++latest

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    testexpression.cpp

HEADERS += \
    testexpression.h

INCLUDEPATH += ../LibExpression ../../DesignLibrary/DesignPattern
DEPENDPATH += $$OUT_PWD/../LibExpression/
LIBS += -L$$OUT_PWD/../LibExpression/debug -lLibExpression
