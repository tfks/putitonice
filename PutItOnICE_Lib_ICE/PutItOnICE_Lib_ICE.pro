#-------------------------------------------------
#
# Project created by QtCreator 2016-01-16T19:07:59
#
#-------------------------------------------------

QT       -= gui

#TARGET = PutItOnICE_Lib_ICE
TARGET = $$OUT_PWD/../PutItOnICE/lib/onicecomm
TEMPLATE = lib

DEFINES += PUTITONICE_LIB_ICE_LIBRARY

SOURCES += src/putitonice_lib_ice.cpp

HEADERS += headers/putitonice_lib_ice.h\
           headers/putitonice_lib_ice_global.h

osx: CONFIG -= no-pkg-config

linux: INCLUDEPATH += /usr/include/

#INCLUDEPATH += `pkg-config --cflags libnice`
#LIBS += `pkg-config --libs libnice`

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += nice


unix {
    #target.path = /usr/lib
    target.path = %{buildDir}/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11
