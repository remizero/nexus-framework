#ifndef APPPROJECT_H
#define APPPROJECT_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"
#include "ProjectAbs.h"

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

      class NEXUSBUILDER_EXPORT AppProject : public ProjectAbs {

        public :
          AppProject ();
          virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
          virtual bool createDirStruct () override;
          virtual bool createProjectFiles () override;
      };
    }
  }
}

#endif // APPPROJECT_H
