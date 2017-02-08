QT       += core gui
QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app

INCLUDEPATH += \
    ../src/Application \
    ../src/Calculation \
    ../src/WidgetComposition \
    ../src/Styles \
    ../Resources \

HEADERS  += \
    $$PWD/Calculation/*.h \
    $$PWD/Application/*.h \
    $$PWD/Styles/*.h \
    $$PWD/WidgetComposition/*.h \

SOURCES += \
    $$PWD/Calculation/*.cpp \
    $$PWD/Application/*.cpp \
    $$PWD/Styles/*.cpp \
    $$PWD/WidgetComposition/*.cpp \

DISTFILES += \
    Todo_list

RESOURCES += \
    Resources/res.qrc

