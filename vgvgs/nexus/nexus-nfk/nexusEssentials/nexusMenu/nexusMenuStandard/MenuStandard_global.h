#ifndef MENUSTANDARD_GLOBAL_H
#define MENUSTANDARD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENUSTANDARD_LIBRARY)
#  define MENUSTANDARD_EXPORT Q_DECL_EXPORT
#else
#  define MENUSTANDARD_EXPORT Q_DECL_IMPORT
#endif

#define NS_MENUSTANDARD    MenuStandard
#define NSLIB_MENUSTANDARD Vgvgs::NexusFramework::Essentials::MenuStandard

#endif // MENUSTANDARD_GLOBAL_H
