QT       += core gui
QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app

INCLUDEPATH += \
    ../src/calculation \

HEADERS  += \
    $$PWD/calculation/*.h \
    calculator.h \
    label_styler.h \
    checkbox_styler.h \
    line_styler.h \
    lcd_styler.h \
    common_layout.h \
    calculator_styler.h \

SOURCES += main.cpp \
    $$PWD/calculation/*.cpp \
    calculator.cpp \
    label_styler.cpp \
    checkbox_styler.cpp \
    line_styler.cpp \
    lcd_styler.cpp \
    common_layout.cpp \
    calculator_styler.cpp \



DISTFILES += \
    Todo_list
