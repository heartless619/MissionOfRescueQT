#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T13:05:31
#
#-------------------------------------------------

QT       += core gui \
        multimedia testlib xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = ProjectTestSuite
TEMPLATE = app


SOURCES += \
    TestSuite.cpp \
    framecountercheck.cpp \
    logger.cpp \
    scorecheck.cpp

HEADERS  += \
    api4testing/bullet.h \
    api4testing/enemy.h \
    api4testing/framecounter.h \
    api4testing/game.h \
    api4testing/globaldef.h \
    api4testing/player.h \
    api4testing/score.h \
    framecountercheck.h \
    logger.h \
    scorecheck.h \
    playercheck.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Project4interviewLib/release/ -lProject4interviewLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Project4interviewLib/debug/ -lProject4interviewLib

INCLUDEPATH += $$PWD/../Project4interviewLib
DEPENDPATH += $$PWD/../Project4interviewLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/release/libProject4interviewLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/debug/libProject4interviewLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/release/Project4interviewLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Project4interviewLib/debug/Project4interviewLib.lib
