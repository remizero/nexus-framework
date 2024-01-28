#ifndef MAINBUILDER_H
#define MAINBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"
#include "NexusBuilderUtils.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT MainBuilder : QObject {

            Q_OBJECT

          public :
            MainBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, NexusBuilder::ProjectId projectType );
        };
      }
    }
  }
}

#endif // MAINBUILDER_H
