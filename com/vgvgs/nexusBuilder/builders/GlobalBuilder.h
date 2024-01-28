#ifndef GLOBALBUILDER_H
#define GLOBALBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilderUtils.h"

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

        class BUILDER_EXPORT GlobalBuilder : QObject {

            Q_OBJECT

          public :
            GlobalBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, QString projectName );
        };
      }
    }
  }
}

#endif // GLOBALBUILDER_H
