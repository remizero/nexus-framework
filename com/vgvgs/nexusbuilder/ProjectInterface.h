#ifndef PROJECTINTERFACE_H
#define PROJECTINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QString>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ProjectInterface {

        public :
          virtual ~ProjectInterface () {}
          virtual bool create () = 0;
          virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) = 0;

        protected :
          virtual bool createDir () = 0;
          virtual bool createStructDir () = 0;
          virtual bool createProjectFiles () = 0;
          virtual bool createResourceFiles () = 0;
      };
    }
  }
}

Q_DECLARE_INTERFACE ( NAMESPACE_LIBRARY_NEXUSBUILDER::ProjectInterface, "com.vgvgs.nexusbuilder.ProjectInterface" )

#endif // PROJECTINTERFACE_H
