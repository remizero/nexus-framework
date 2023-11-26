#ifndef SINGLEINSTANCE_GLOBAL_H
#define SINGLEINSTANCE_GLOBAL_H

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


#if defined(SINGLEINSTANCE_LIBRARY)
#  define SINGLEINSTANCE_EXPORT Q_DECL_EXPORT
#else
#  define SINGLEINSTANCE_EXPORT Q_DECL_IMPORT
#endif

#define NS_SINGLEINSTANCE    SingleInstance
#define NSLIB_SINGLEINSTANCE Com::Vgvgs::NexusFramework::SingleInstance

#endif // SINGLEINSTANCE_GLOBAL_H
