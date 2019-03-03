#-------------------------------------------------
#
# Project created by QtCreator 2019-01-20T14:39:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialMgmtP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialmgmt.cpp \
    serialconnectwindow.cpp \
    serialreciver.cpp

HEADERS  += mainwindow.h \
    serialmgmt.h \
    serialconnectwindow.h \
    serialreciver.h

FORMS    += mainwindow.ui \
    serialconnectwindow.ui
