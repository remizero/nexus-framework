#ifndef STRINGS_H
#define STRINGS_H

// Librerías Internas
// Internal Libraries
#include "Utils_global.h"
#include "Files.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QFile>
#include <QTextStream>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Strings {

          public :
            static QString capitalize ( QString string );
            static QString load ( QString fileName, bool readOnly = false );
            static QString normalizeClassName ( QString string );
            static bool save ( QString fileName, QString text );
        };
      }
    }
  }
}

#endif // STRINGS_H
