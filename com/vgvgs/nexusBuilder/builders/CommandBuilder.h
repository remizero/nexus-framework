#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H

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

        class BUILDER_EXPORT CommandBuilder : QObject {

            Q_OBJECT

          public :
            CommandBuilder ( QObject *parent = nullptr );
            QString build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType );
        };
      }
    }
  }
}

#endif // COMMANDBUILDER_H
