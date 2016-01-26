#-------------------------------------------------
#
# Project created by QtCreator 2016-01-16T17:45:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PutItOnICE
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/taskbar.cpp

HEADERS  += headers/mainwindow.h \
            headers/taskbar.h

FORMS    += ui/mainwindow.ui

RESOURCES += \
    mainwindow.qrc



unix {
    #target.path = /usr/lib
    target.path = %{buildDir}/lib
    INSTALLS += target
}

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE_Lib_UI/release/ -loniceui
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE_Lib_UI/debug/ -loniceui
#else:unix: LIBS += -L$$OUT_PWD/../PutItOnICE_Lib_UI/ -loniceui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecommon
else:unix: LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecommon

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecomm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecomm
else:unix: LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -lonicecommon

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -loniceui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -loniceui
else:unix: LIBS += -L$$OUT_PWD/../PutItOnICE/lib/ -loniceui

INCLUDEPATH += $$PWD/../PutItOnICE_Lib_UI
DEPENDPATH += $$PWD/../PutItOnICE_Lib_UI

QMAKE_CXXFLAGS += -std=c++11