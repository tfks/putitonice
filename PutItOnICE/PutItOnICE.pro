#-------------------------------------------------
#
# Project created by QtCreator 2016-01-16T17:45:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PutItOnICE/putitonice
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/taskbar.cpp \
           src/settingsdialog.cpp \
           src/mainmenu.cpp

HEADERS  += headers/mainwindow.h \
            headers/taskbar.h \
            headers/settingsdialog.h \
            headers/mainmenu.h

FORMS    += ui/mainwindow.ui \
            ui/settingsdialog.ui \
            ui/mainmenu.ui

RESOURCES += \
    mainwindow.qrc

include(../DestDir.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecommon
else:unix: LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecommon

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecomm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecomm
else:unix: LIBS += -L$$DESTDIR/PutItOnICE/lib/ -lonicecommon

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -loniceui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/PutItOnICE/lib/ -loniceui
else:unix: LIBS += -L$$DESTDIR/PutItOnICE/lib/ -loniceui

INCLUDEPATH += $$PWD/../PutItOnICE_Lib_UI
DEPENDPATH += $$PWD/../PutItOnICE_Lib_UI

QMAKE_CXXFLAGS += -std=c++11


unix {
    #target.path = /usr/lib
    target.path = $$DESTDIR/PutItOnICE
    INSTALLS += target
}
