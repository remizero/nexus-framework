#ifndef CONSOLE_GLOBAL_H
#define CONSOLE_GLOBAL_H

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


#if defined(CONSOLE_LIBRARY)
#  define CONSOLE_EXPORT Q_DECL_EXPORT
#else
#  define CONSOLE_EXPORT Q_DECL_IMPORT
#endif

#define NS_CONSOLE    Console
#define NSLIB_CONSOLE Com::Vgvgs::NexusFramework::Essentials::Console

#endif // CONSOLE_GLOBAL_H
