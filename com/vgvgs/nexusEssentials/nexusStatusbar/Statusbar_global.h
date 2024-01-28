#ifndef STATUSBAR_GLOBAL_H
#define STATUSBAR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STATUSBAR_LIBRARY)
#  define STATUSBAR_EXPORT Q_DECL_EXPORT
#else
#  define STATUSBAR_EXPORT Q_DECL_IMPORT
#endif

#define NS_STATUSBAR    Statusbar
#define NSLIB_STATUSBAR Com::Vgvgs::NexusFramework::Essentials::Statusbar

#endif // STATUSBAR_GLOBAL_H
