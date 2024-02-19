#ifndef VERSIONBUILDER_H
#define VERSIONBUILDER_H

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
#include <QString>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT VersionBuilder : QObject {

            Q_OBJECT

          public :
            VersionBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, QString prefix, QString fileName );
        };
      }
    }
  }

#endif // VERSIONBUILDER_H
