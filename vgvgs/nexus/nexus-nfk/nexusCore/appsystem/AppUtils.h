#ifndef APPUTILS_H
#define APPUTILS_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries
#include "Strings.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QLatin1String>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT AppUtils {

          public :
            static QString normalizePath ( QString path );
            static QString pathTo ( QString path );
            static QString relativePath ( QString rootPath, QString path );
            static QString loadStyleSheet ();
        };
      }
    }
  }

#endif // APPUTILS_H
