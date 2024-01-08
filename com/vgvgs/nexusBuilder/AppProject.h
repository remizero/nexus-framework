#ifndef APPPROJECT_H
#define APPPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectAbs.h"
#include "builders/MainBuilder.h"
#include "builders/ConfigBuilder.h"

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

        class BUILDER_EXPORT AppProject : public ProjectAbs {

            Q_OBJECT

          public :
            AppProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            virtual bool createDirStruct () override;
            bool createProjectFiles () override;

          protected :
              MainBuilder *mainBuilder;
            ConfigBuilder *configBuilder;
        };
      }
    }
  }
}

#endif // APPPROJECT_H
