#ifndef NEXUSBUILDER_H
#define NEXUSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "projectType/ConsoleProject.h"
#include "projectType/GuiProject.h"
#include "projectType/NexusProject.h"
#include "projectType/PluginProject.h"
#include "projectType/ShareLibraryProject.h"
#include "projectType/SimpleGuiProject.h"
#include "projectType/StaticLibraryProject.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QMetaType>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT NexusBuilder : public QObject {

            Q_OBJECT

          public :

            enum ProjectId {

              CONSOLE,
              GUI,
              NEXUS,
              PLUGIN,
              SHARE,
              SIMPLEGUI,
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
}

#endif // NEXUSBUILDER_H
