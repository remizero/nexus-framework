#ifndef RESOURCES_GLOBAL_H
#define RESOURCES_GLOBAL_H

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


#if defined(RESOURCES_LIBRARY)
#  define RESOURCES_EXPORT Q_DECL_EXPORT
#else
#  define RESOURCES_EXPORT Q_DECL_IMPORT
#endif


#define NS_RESOURCES    Resources
#define NSLIB_RESOURCES Com::Vgvgs::NexusFramework::Resources

#endif // RESOURCES_GLOBAL_H
