#ifndef BUILDER_GLOBAL_H
#define BUILDER_GLOBAL_H

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


#if defined(BUILDER_LIBRARY)
#  define BUILDER_EXPORT Q_DECL_EXPORT
#else
#  define BUILDER_EXPORT Q_DECL_IMPORT
#endif

#define NS_BUILDER    Builder
#define NSLIB_BUILDER Com::Vgvgs::NexusFramework::Builder

#endif // BUILDER_GLOBAL_H
