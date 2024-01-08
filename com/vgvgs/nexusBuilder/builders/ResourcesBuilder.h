#ifndef RESOURCESBUILDER_H
#define RESOURCESBUILDER_H

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

        class BUILDER_EXPORT ResourcesBuilder {

          public :
            ResourcesBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType );
        };
      }
    }
  }
}

#endif // RESOURCESBUILDER_H
