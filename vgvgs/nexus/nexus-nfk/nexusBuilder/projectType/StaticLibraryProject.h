#ifndef STATICLIBRARYPROJECT_H
#define STATICLIBRARYPROJECT_H

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
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT StaticLibraryProject : public LibraryProject {

            Q_OBJECT

          public :
            StaticLibraryProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            // bool createDirStruct () override { return true; }
            // bool createProjectFiles () override;
        };
      }
    }
  }

#endif // STATICLIBRARYPROJECT_H
