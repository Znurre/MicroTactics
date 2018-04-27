DEPENDPATH += ../game
INCLUDEPATH += ../game

CONFIG += c++11 link_pkgconfig

TEMPLATE = app
TARGET = MicroTactics

SOURCES += \
    main.cpp

PKGCONFIG += sdl2

LIBS += -lMagnum -lMagnumSdl2Application -lCorradeUtility -lMagnumShaders -L../game -lgame
