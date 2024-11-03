#ifndef DOCUMENTATION_GLOBAL_H
#define DOCUMENTATION_GLOBAL_H

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


#if defined(DOCUMENTATION_LIBRARY)
#define DOCUMENTATION_EXPORT Q_DECL_EXPORT
#else
#define DOCUMENTATION_EXPORT Q_DECL_IMPORT
#endif

#define NS_DOCUMENTATION    Documentation
#define NSLIB_DOCUMENTATION Vgvgs::NexusFramework::Documentation

#endif // DOCUMENTATION_GLOBAL_H
