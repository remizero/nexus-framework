#ifndef GUIAPPPROJECT_H
#define GUIAPPPROJECT_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "AppProject.h"

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

        class BUILDER_EXPORT GuiAppProject : public AppProject {

            Q_OBJECT

          public :
            GuiAppProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            // bool createProjectFiles () override;
        };
      }
    }
  }

#endif // GUIAPPPROJECT_H
