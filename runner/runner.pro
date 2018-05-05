DEPENDPATH += ../game
INCLUDEPATH += ../game

CONFIG += c++11

TEMPLATE = app
TARGET = MicroTactics

SOURCES += \
    main.cpp

LIBS += -L../game -lgame
