#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T15:25:21
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_PlayerTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEPENDPATH += ../game
INCLUDEPATH += ../game

SOURCES += \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L../game -lgame

HEADERS += \
    PlayerTests.h \
    KeyInputHandlerTests.h \
    Mock.h \
    PlayerTurnHandlerTests.h
