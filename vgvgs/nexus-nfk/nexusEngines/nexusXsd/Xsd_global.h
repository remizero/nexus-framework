#ifndef XSD_GLOBAL_H
#define XSD_GLOBAL_H

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

#if defined(XSD_LIBRARY)
#  define XSD_EXPORT Q_DECL_EXPORT
#else
#  define XSD_EXPORT Q_DECL_IMPORT
#endif

#define NS_XSD    Xsd
#define NSLIB_XSD Vgvgs::NexusFramework::Engines::Xsd

#endif // XSD_GLOBAL_H
