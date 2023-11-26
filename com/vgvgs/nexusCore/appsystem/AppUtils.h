#ifndef APPUTILS_H
#define APPUTILS_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT AppUtils {

          public :
            static QString normalizePath ( QString path );
            static QString pathTo ( QString path );
            static QString relativePath ( QString rootPath, QString path );
        };
      }
    }
  }
}

#endif // APPUTILS_H
