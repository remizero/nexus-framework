#ifndef EXPORTSBUILDER_H
#define EXPORTSBUILDER_H

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
#include <QStringList>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ExportsBuilder : QObject {

            Q_OBJECT

          public :
            ExportsBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, const QStringList &resourceList );
        };
      }
    }
  }
}

#endif // EXPORTSBUILDER_H
