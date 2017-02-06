QT       += core gui
QT += widgets

TARGET = SpecialCalculator
TEMPLATE = app

INCLUDEPATH += \
    ../src/calculation \
    ../src/config \
    ../src/app \
    ../resources \

HEADERS  += \
    $$PWD/calculation/*.h \
    $$PWD/config/*.h \
    $$PWD/app/*.h \

SOURCES += \
    $$PWD/calculation/*.cpp \
    $$PWD/config/*.cpp \
    $$PWD/app/*.cpp \

DISTFILES += \
    Todo_list

RESOURCES += \
    resources/res.qrc

