#ifndef MENUBAR_GLOBAL_H
#define MENUBAR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENUBAR_LIBRARY)
#  define MENUBAR_EXPORT Q_DECL_EXPORT
#else
#  define MENUBAR_EXPORT Q_DECL_IMPORT
#endif

#define NS_MENUBAR    Menubar
#define NSLIB_MENUBAR Vgvgs::NexusFramework::Essentials::Menubar

#endif // MENUBAR_GLOBAL_H
