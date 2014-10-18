#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T20:45:59
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timerpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    countdowntimer.cpp \
    dicewidget.cpp \
    countdownoptions.cpp \
    settimechooser.cpp \
    countdownoptionswidget.cpp

HEADERS  += mainwindow.h \
    countdowntimer.h \
    dicewidget.h \
    countdownoptions.h \
    settimechooser.h \
    countdownoptionswidget.h

FORMS    += mainwindow.ui \
    countdowntimer.ui \
    dicewidget.ui \
    settimechooser.ui \
    countdownoptionswidget.ui

OTHER_FILES +=

RESOURCES += \
    resources.qrc
