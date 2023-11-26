#ifndef SHARE_GLOBAL_H
#define SHARE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SHARE_LIBRARY)
#  define SHARE_EXPORT Q_DECL_EXPORT
#else
#  define SHARE_EXPORT Q_DECL_IMPORT
#endif

#endif // SHARE_GLOBAL_H
