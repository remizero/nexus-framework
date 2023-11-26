#ifndef SPLASHSCREEN_GLOBAL_H
#define SPLASHSCREEN_GLOBAL_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QtCore/qglobal.h>

// Librerías C++
// C++ Libraries


#if defined(SPLASHSCREEN_LIBRARY)
#  define SPLASHSCREEN_EXPORT Q_DECL_EXPORT
#else
#  define SPLASHSCREEN_EXPORT Q_DECL_IMPORT
#endif

#define NS_SPLASHSCREEN    SplashScreen
#define NSLIB_SPLASHSCREEN Com::Vgvgs::NexusFramework::SplashScreen

#endif // SPLASHSCREEN_GLOBAL_H
