#ifndef CONSOLEPROJECT_H
#define CONSOLEPROJECT_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"
#include "AppProject.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ConsoleProject : public AppProject {

        public :
          ConsoleProject ();
          void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
          bool createDirStruct () override;
          bool createProjectFiles () override;
      };
    }
  }
}

#endif // CONSOLEPROJECT_H
