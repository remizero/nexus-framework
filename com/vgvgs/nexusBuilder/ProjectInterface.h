#ifndef PROJECTINTERFACE_H
#define PROJECTINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QString>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ProjectInterface {

          public :
            virtual ~ProjectInterface () {}
            virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) = 0;
            virtual bool createProjectDir () = 0;
            virtual bool createProFile () = 0;
            virtual bool createDirStruct () = 0;
            virtual bool createProjectFiles () = 0;
            virtual bool createCommandFiles () = 0;
            virtual bool createResourceFiles () = 0;
        };
      }
    }
  }
}

Q_DECLARE_INTERFACE ( NSLIB_BUILDER::ProjectInterface, "com.vgvgs.nexusBuilder.ProjectInterface" )

#endif // PROJECTINTERFACE_H
