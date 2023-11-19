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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT AppProject : public ProjectAbs {

        public :
          // AppProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false );
          AppProject ();
          virtual bool create () override;
          virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;

        protected :
          virtual bool createProjectFiles () override;
          virtual bool createStructDir () override { return true; }
          virtual bool createResourceFiles () override { return true; }
      };
    }
  }
}

#endif // APPPROJECT_H
