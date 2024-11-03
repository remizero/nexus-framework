#ifndef SYSTEM_H
#define SYSTEM_H

// Librerías Internas
// Internal Libraries
#include "Utils_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDateTime>
#include <QDebug>
#include <QProcess>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_VGVGS {

  namespace NS_NEXUS {

    namespace NS_UTILS {

      class UTILS_EXPORT System {

        public :
          static QString getNameUser ();
          static QString getUser ();
      };
    }
  }
}

#endif // SYSTEM_H
