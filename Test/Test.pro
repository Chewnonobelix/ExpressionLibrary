QT += testlib
QT += gui core widgets network xml testlib
CONFIG += qt warn_on depend_includepath testcase c++17

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    testexpression.cpp

HEADERS += \
    testexpression.h

INCLUDEPATH += ../LibExpression ../../DesignLibrary/DesignPattern
DEPENDPATH += $$OUT_PWD/../LibExpression/
win32:CONFIG(debug, debug| release): LIBS += -L$$OUT_PWD/../LibExpression/debug
else:win32:CONFIG(release, debug| release): LIBS += -L$$OUT_PWD/../LibExpression/release
else:unix:CONFIG(debug, debug| release): LIBS += -L$$OUT_PWD/../LibExpression/
LIBS += -lLibExpression
