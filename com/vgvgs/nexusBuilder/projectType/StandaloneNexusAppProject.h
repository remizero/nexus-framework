#ifndef STANDALONENEXUSAPPPROJECT_H
#define STANDALONENEXUSAPPPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "projectType/NexusAppProject.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT StandaloneNexusAppProject : public NexusAppProject {

            Q_OBJECT

          public :
            StandaloneNexusAppProject ( QObject *parent = nullptr );
            // void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            // bool createDirStruct () override;
            // bool createProjectFiles () override;
        };
      }
    }
  }
}

#endif // STANDALONENEXUSAPPPROJECT_H
