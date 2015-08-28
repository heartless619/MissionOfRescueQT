#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T10:19:53
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Project4interviewLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Bullet.cpp \
    Enemy.cpp \
    Player.cpp \
    Game.cpp    \
    Score.cpp \
    FrameCounter.cpp \

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Player.h \
    Score.h \
    Game.h  \
    Globaldef.h \
    FrameCounter.h \


unix {
    target.path = /usr/lib
    INSTALLS += target
}
