#ifndef NEXUSBUILDER_H
#define NEXUSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"
#include "projectType/ConsoleProject.h"
#include "projectType/GuiProject.h"
#include "projectType/NexusProject.h"
#include "projectType/PluginProject.h"
#include "projectType/ShareLibraryProject.h"
#include "projectType/StaticLibraryProject.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QMetaType>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT NexusBuilder : public QObject {

          Q_OBJECT

        public :

          enum ProjectId {

            CONSOLE,
            GUI,
            NEXUS,
            PLUGIN,
            SHARE,
            STATIC,
            NUM_PROJECTS
          };
          Q_ENUM ( ProjectId )
          NexusBuilder ();

          ProjectInterface *create ( ProjectId projectId );
          static const char *getProjectClassName ( ProjectId projectId );
          static ProjectId stringToProjectId ( const QString &projectType );
      };
    }
  }
}

#endif // NEXUSBUILDER_H
