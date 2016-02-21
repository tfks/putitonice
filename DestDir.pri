 
isEmpty(DESTDIR) {
        CONFIG(debug, debug|release) {
            DESTDIR=$$PWD/Build/Debug
        }

        CONFIG(release, debug|release) {
            DESTDIR=$$PWD/Build/Release
        }
}