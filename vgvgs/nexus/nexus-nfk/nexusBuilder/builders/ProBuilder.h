#ifndef PROBUILDER_H
#define PROBUILDER_H

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ProBuilder : QObject {

            Q_OBJECT

          public :
            ProBuilder ( QObject *parent = nullptr );
            QString build ( QString projectPath, QString resource, const QString &projectName, NexusBuilder::ProjectId projectType );
        };
      }
    }
  }

#endif // PROBUILDER_H
