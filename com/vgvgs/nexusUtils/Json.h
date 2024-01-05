#ifndef JSON_H
#define JSON_H

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
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QString>
#include <QVariant>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Json {

          public :
            static QJsonDocument *load ( QString fileName, bool readOnly = false );
            static bool save ( QJsonDocument *jsonDocument, QString fileName );
        };
      }
    }
  }
}

#endif // JSON_H
