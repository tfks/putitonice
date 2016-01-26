TEMPLATE = subdirs
SUBDIRS += $$PWD/PutItOnICE/PutItOnICE.pro \
           $$PWD/PutItOnICE_Lib_Common/PutItOnICE_Lib_Common.pro \
           $$PWD/PutItOnICE_Lib_ICE/PutItOnICE_Lib_ICE.pro \
           $$PWD/PutItOnICE_Lib_UI/PutItOnICE_Lib_UI.pro

$PWD/PutItOnICE/src/PutItOnICE.pro.depends = $$PWD/PutItOnICE_Lib_Common/PutItOnICE_Lib_Common.pro
$PWD/PutItOnICE/src/PutItOnICE.pro.depends = $$PWD/PutItOnICE_Lib_ICE/PutItOnICE_Lib_ICE.pro
$PWD/PutItOnICE/src/PutItOnICE.pro.depends = $$PWD/PutItOnICE_Lib_UI/PutItOnICE_Lib_UI.pro


