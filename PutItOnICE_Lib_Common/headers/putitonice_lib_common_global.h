#ifndef PUTITONICE_LIB_COMMON_GLOBAL_H
#define PUTITONICE_LIB_COMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PUTITONICE_LIB_COMMON_LIBRARY)
#  define PUTITONICE_LIB_COMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PUTITONICE_LIB_COMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PUTITONICE_LIB_COMMON_GLOBAL_H