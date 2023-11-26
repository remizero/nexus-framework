#ifndef PLUGINPROJECT_H
#define PLUGINPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "LibraryProject.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT PluginProject : public LibraryProject {

          public :
            PluginProject ();
            void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
            bool createDirStruct () override { return true; }
            bool createProjectFiles () override;
        };
      }
    }
  }
}

#endif // PLUGINPROJECT_H
