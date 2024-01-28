#ifndef MENURIBBON_GLOBAL_H
#define MENURIBBON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENURIBBON_LIBRARY)
#  define MENURIBBON_EXPORT Q_DECL_EXPORT
#else
#  define MENURIBBON_EXPORT Q_DECL_IMPORT
#endif

#define NS_MENURIBBON    MenuRibbon
#define NSLIB_MENURIBBON Com::Vgvgs::NexusFramework::Essentials::MenuRibbon

#endif // MENURIBBON_GLOBAL_H
