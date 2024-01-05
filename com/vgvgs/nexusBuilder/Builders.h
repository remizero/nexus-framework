#ifndef BUILDERS_H
#define BUILDERS_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT Builders {

          public :
            Builders ();

            QString loadResource ( const QString &resourcePath );
        };
      }
    }
  }
}

#endif // BUILDERS_H
