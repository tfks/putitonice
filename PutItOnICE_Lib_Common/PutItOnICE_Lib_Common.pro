#-------------------------------------------------
#
# Project created by QtCreator 2016-01-16T17:47:04
#
#-------------------------------------------------

QT       -= gui

TARGET = $$DESTDIR/PutItOnICE/lib/onicecommon
TEMPLATE = lib

DEFINES += PUTITONICE_LIB_COMMON_LIBRARY

SOURCES += src/putitonice_lib_common.cpp

HEADERS += headers/putitonice_lib_common.h \
           headers/putitonice_lib_common_global.h

unix {
    #target.path = /usr/lib
    target.path = $$DESTDIR/PutItOnICE/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11

include(../DestDir.pri)
