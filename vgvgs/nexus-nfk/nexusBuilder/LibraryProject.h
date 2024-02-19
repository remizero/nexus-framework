#ifndef LIBRARYPROJECT_H
#define LIBRARYPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectAbs.h"
#include "builders/ExportsBuilder.h"
#include "builders/GlobalBuilder.h"
#include "builders/ResourcesBuilder.h"
#include "builders/VersionBuilder.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT LibraryProject : public ProjectAbs {

            Q_OBJECT

          public :
            LibraryProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            bool createDirStruct () override;
            bool createProjectFiles () override;

          protected :
              ExportsBuilder *exportsBuilder;
               GlobalBuilder *globalBuilder;
              VersionBuilder *versionBuilder;
            ResourcesBuilder *resourcesBuilder;
        };
      }
    }
  }

#endif // LIBRARYPROJECT_H
