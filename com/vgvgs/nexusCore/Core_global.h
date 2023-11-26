#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H

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


#if defined(CORE_LIBRARY)
#  define CORE_EXPORT Q_DECL_EXPORT
#else
#  define CORE_EXPORT Q_DECL_IMPORT
#endif

#define NS_CORE    Core
#define NSLIB_CORE Com::Vgvgs::NexusFramework::Core

#endif // CORE_GLOBAL_H
