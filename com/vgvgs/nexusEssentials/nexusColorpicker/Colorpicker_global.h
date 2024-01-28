#ifndef COLORPICKER_GLOBAL_H
#define COLORPICKER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COLORPICKER_LIBRARY)
#  define COLORPICKER_EXPORT Q_DECL_EXPORT
#else
#  define COLORPICKER_EXPORT Q_DECL_IMPORT
#endif

#define NS_COLORPICKER    Colorpicker
#define NSLIB_COLORPICKER Com::Vgvgs::NexusFramework::Essentials::Colorpicker

#endif // COLORPICKER_GLOBAL_H
