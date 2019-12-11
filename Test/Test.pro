QT += testlib
QT += gui core widgets network xml xmlpatterns testlib
CONFIG += qt warn_on depend_includepath testcase c++14

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    testexpression.cpp

HEADERS += \
    testexpression.h

INCLUDEPATH += ../LibExpression/Core ../LibExpression/Operation
