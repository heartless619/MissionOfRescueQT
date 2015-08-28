#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T13:38:58
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project4interview
TEMPLATE = app


SOURCES += \
    Main.cpp \




HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Player.h \
    Score.h \
    Globaldef.h \
    FrameCounter.h \

RESOURCES += \
    res.qrc \
    res.qrc

# Adds the Project4interviewLib.lib to the linker


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Project4interviewLib/release/ -lProject4interviewLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Project4interviewLib/debug/ -lProject4interviewLib

INCLUDEPATH += $$PWD/../Project4interviewLib
DEPENDPATH += $$PWD/../Project4interviewLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/release/libProject4interviewLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/debug/libProject4interviewLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/release/Project4interviewLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/debug/Project4interviewLib.lib
