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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ConsoleProject : public AppProject {

        public :
          // ConsoleProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false );
          ConsoleProject ();
          bool create () override;
          void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;

        protected :
          bool createProjectFiles () override;
          bool createStructDir () override { return true; }
          bool createResourceFiles () override { return true; }
      };
    }
  }
}

#endif // CONSOLEPROJECT_H
