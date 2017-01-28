QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app


SOURCES += main.cpp \
    calculator.cpp \
    calculatorstyler.cpp

HEADERS  += \
    calculator.h \
    calculatorstyler.h

DISTFILES += \
    Todo_list
