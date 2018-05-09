######################################################################
# Automatically generated by qmake (3.1) Sat Nov 11 15:39:37 2017
######################################################################

TEMPLATE = lib
TARGET = game
INCLUDEPATH += .

CONFIG += c++11

DISTFILES += \
	shader.vert \
	shader.frag

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Player.h \
    KeyInputHandler.h \
    IPlayerTurnHandler.h \
    PlayerTurnHandler.h \
    IPlayer.h \
    PlayerHandler.h \
    IPlayerHandler.h \
    Board.h \
    IDrawable.h \
    IMap.h \
    Map.h \
    Window.h \
    Character.h \
    ICharacterProperties.h \
    IPalette.h \
    Palette1.h \
    IFaceTemplate.h \
    CuteFaceTemplate.h \
    IObject.h \
    ISceneNode.h \
    ICharacterProperties.h

SOURCES += \
    KeyInputHandler.cpp \
    PlayerTurnHandler.cpp \
    PlayerHandler.cpp \
    Board.cpp \
    Map.cpp \
    Window.cpp \
    Player.cpp \
    Character.cpp \
    Palette1.cpp \
    CuteFaceTemplate.cpp
