QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app


SOURCES += main.cpp \
    calculator.cpp \
    label_styler.cpp

HEADERS  += \
    calculator.h \
    label_syler.h

DISTFILES += \
    Todo_list
