#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T12:26:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $$DESTDIR/PutItOnICE/lib/oniceui
TEMPLATE = lib

DEFINES += PUTITONICE_LIB_UI_LIBRARY

SOURCES += src/putitonice_lib_ui.cpp \
           src/icemdiarea.cpp \
           src/icemdisubwindow.cpp

HEADERS += headers/putitonice_lib_ui.h \
           headers/putitonice_lib_ui_global.h \
           headers/icemdiarea.h \
           headers/backgrounddrawstyleflags.h \
           headers/icemdisubwindow.h

include(../DestDir.pri)

unix {
    #target.path = /usr/lib
    target.path = $$DESTDIR/PutItOnICE/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11


