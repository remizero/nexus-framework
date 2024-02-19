#ifndef SYSTEMTRAYICON_GLOBAL_H
#define SYSTEMTRAYICON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SYSTEMTRAYICON_LIBRARY)
#  define SYSTEMTRAYICON_EXPORT Q_DECL_EXPORT
#else
#  define SYSTEMTRAYICON_EXPORT Q_DECL_IMPORT
#endif

#define NS_SYSTEMTRAYICON    Systemtrayicon
#define NSLIB_SYSTEMTRAYICON Vgvgs::NexusFramework::Essentials::Systemtrayicon

#endif // SYSTEMTRAYICON_GLOBAL_H
