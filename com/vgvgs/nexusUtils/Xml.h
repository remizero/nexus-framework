#ifndef XML_H
#define XML_H

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
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QVariant>
#include <QtXml/QDomDocument>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Xml {

          public :
            static QDomDocument *load ( QString fileName, bool readOnly = false );
            static bool save ( QDomDocument *domDocument, QString fileName );
        };
      }
    }
  }
}

#endif // XML_H
