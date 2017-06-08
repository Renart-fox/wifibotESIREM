#-------------------------------------------------
#
# Project created by QtCreator 2017-05-11T08:20:16
#
#-------------------------------------------------

QT       += core gui
QT += network
QMAKE_CXXFLAGS += -std=c++11
QT += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wifibotKevinBaptiste
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    error.cpp \
    changeip.cpp \
    tcpcam.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    error.h \
    changeip.h \
    networkingopt.h \
    tcpcam.h

FORMS    += mainwindow.ui \
    error.ui \
    changeip.ui

RESOURCES +=

DISTFILES +=
