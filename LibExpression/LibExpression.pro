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
    Operation/Logic/andexpression.cpp \
    Operation/Logic/conjonctiveform.cpp \
    Operation/Logic/disjonctiveform.cpp \
    Operation/Logic/equivalentexpression.cpp \
    Operation/Logic/impliedexpression.cpp \
    Operation/Logic/noexpression.cpp \
    Operation/Logic/orexpression.cpp \

HEADERS += Core/expression.h\
        Core/expression_global.h \
    Core/binaryexpression.h \
    Core/naryexpression.h \
    Operation/Arithmetic/additionexpression.h \
    Operation/Arithmetic/divisionexpression.h \
    Operation/Arithmetic/minusexpression.h \
    Operation/Arithmetic/multiplicationexpression.h \
    Operation/Comparaison/equalexpression.h \
    Operation/Comparaison/comparaisonexpression.h \
    Operation/Comparaison/equalexpression.h \
    Operation/Comparaison/inferiorexpression.h \
    Operation/Comparaison/superiorexpression.h \
    Operation/Logic/andexpression.h \
    Operation/Logic/conjonctiveform.h \
    Operation/Logic/disjonctiveform.h \
    Operation/Logic/equivalentexpression.h \
    Operation/Logic/impliedexpression.h \
    Operation/Logic/noexpression.h \
    Operation/Logic/orexpression.h \
    Core/unaryexpression.h \
    Core/valueexpression.h \
    Core/constantexpression.h

INCLUDEPATH = Core/ Operation/ ../../DesignLibrary/DesignPattern

CONFIG += c++17
