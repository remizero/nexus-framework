#ifndef LIBRARYPROJECT_H
#define LIBRARYPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectAbs.h"

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

        class BUILDER_EXPORT LibraryProject : public ProjectAbs {

            Q_OBJECT

          public :
            LibraryProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
            // virtual bool createDirStruct () override { return true; }
            // virtual bool createProjectFiles () override;
        };
      }
    }
  }
}

#endif // LIBRARYPROJECT_H
