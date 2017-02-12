TARGET = SpecialCalculator
TEMPLATE = app

QT += core gui widgets

INCLUDEPATH += \
    $$PWD/Application \
    $$PWD/Calculation \
    $$PWD/WidgetComposition \
    $$PWD/Styles

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

