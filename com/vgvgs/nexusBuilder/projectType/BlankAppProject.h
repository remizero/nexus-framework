#ifndef BLANKAPPPROJECT_H
#define BLANKAPPPROJECT_H

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


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT BlankAppProject : public AppProject {

            Q_OBJECT

          public :
            BlankAppProject ( QObject *parent = nullptr );
            void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
        };
      }
    }
  }
}

#endif // BLANKAPPPROJECT_H
