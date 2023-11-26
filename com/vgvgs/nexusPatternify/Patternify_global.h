#ifndef PATTERNIFY_GLOBAL_H
#define PATTERNIFY_GLOBAL_H

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


#if defined(PATTERNIFY_LIBRARY)
#  define PATTERNIFY_EXPORT Q_DECL_EXPORT
#else
#  define PATTERNIFY_EXPORT Q_DECL_IMPORT
#endif

#define NS_PATTERNIFY    Patternify
#define NSLIB_PATTERNIFY Com::Vgvgs::NexusFramework::Patternify

#endif // PATTERNIFY_GLOBAL_H
