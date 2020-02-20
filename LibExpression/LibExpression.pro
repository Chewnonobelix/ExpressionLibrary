#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T09:28:14
#
#-------------------------------------------------

QT       -= gui

TARGET = LibExpression
TEMPLATE = lib

DEFINES += EXPRESSION_LIBRARY

SOURCES += \
    Operation/conjonctiveform.cpp \
    Operation/disjonctiveform.cpp \
    Operation/equivalentexpression.cpp \
    Operation/andexpression.cpp \
    Operation/orexpression.cpp \
    Operation/noexpression.cpp \
    Operation/impliedexpression.cpp

HEADERS += Core/expression.h\
        Core/expression_global.h \
    Core/binaryexpression.h \
    Core/naryexpression.h \
    Operation/additionexpression.h \
    Operation/conjonctiveform.h \
    Operation/disjonctiveform.h \
    Operation/divisionexpression.h \
    Operation/minusexpression.h \
    Operation/multiplicationexpression.h \
    Operation/andexpression.h \
    Core/unaryexpression.h \
    Core/valueexpression.h \
    Operation/equivalentexpression.h \
    Operation/impliedexpression.h \
    Operation/orexpression.h \
    Operation/noexpression.h \
    Core/constantexpression.h

INCLUDEPATH = Core/ Operation/ ../../DesignLibrary/DesignPattern

CONFIG += c++17
