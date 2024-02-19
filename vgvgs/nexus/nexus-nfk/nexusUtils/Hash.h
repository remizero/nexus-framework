#ifndef HASH_H
#define HASH_H

// Librerías Internas
// Internal Libraries
#include "Utils_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QString>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Hash {

          public :
            static QString generate ( const QString &inputString, QCryptographicHash::Algorithm algorithm = QCryptographicHash::Md5 );
        };
      }
    }
  }

#endif // HASH_H
