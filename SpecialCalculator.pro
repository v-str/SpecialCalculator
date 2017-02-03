QT       += core gui
QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app

INCLUDEPATH += \
    ../src/calculation \

HEADERS  += \
    $$PWD/calculation/*.h \
    calculator.h \
    calculator_style_configurator.h

SOURCES += main.cpp \
    $$PWD/calculation/*.cpp \
    calculator.cpp \
    calculator_style_configurator.cpp



DISTFILES += \
    Todo_list
