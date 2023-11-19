#ifndef LIBRARYPROJECT_H
#define LIBRARYPROJECT_H

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

      class NEXUSBUILDER_EXPORT LibraryProject : public ProjectAbs {

        public :
          // LibraryProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false );
          LibraryProject ();
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

#endif // LIBRARYPROJECT_H
