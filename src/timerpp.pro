#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T20:45:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timerpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    countdowntimer.cpp

HEADERS  += mainwindow.h \
    countdowntimer.h

FORMS    += mainwindow.ui \
    countdowntimer.ui
