#ifndef COLORBOX_GLOBAL_H
#define COLORBOX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COLORBOX_LIBRARY)
#  define COLORBOX_EXPORT Q_DECL_EXPORT
#else
#  define COLORBOX_EXPORT Q_DECL_IMPORT
#endif

#define NS_COLORBOX    Colorbox
#define NSLIB_COLORBOX Com::Vgvgs::NexusFramework::Essentials::Colorbox

#endif // COLORBOX_GLOBAL_H
