QT       += core gui
QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app

INCLUDEPATH += \
    ../src/calculation \

HEADERS  += \
    $$PWD/calculation/*.h \
    calculator.h \
    common_layout.h \
    calculator_style_configurator.h \
    label_style_configurator.h \
    checkbox_style_configurator.h \
    lcd_style_configurator.h \
    line_style_configurator.h

SOURCES += main.cpp \
    $$PWD/calculation/*.cpp \
    calculator.cpp \
    common_layout.cpp \
    calculator_style_configurator.cpp \
    label_style_configurator.cpp \
    checkbox_style_configurator.cpp \
    lcd_style_configurator.cpp \
    line_style_configurator.cpp



DISTFILES += \
    Todo_list
