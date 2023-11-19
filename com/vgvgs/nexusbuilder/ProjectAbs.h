#ifndef PROJECTABS_H
#define PROJECTABS_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDir>
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ProjectAbs : public ProjectInterface {

          Q_INTERFACES ( NAMESPACE_LIBRARY_NEXUSBUILDER::ProjectInterface )

        public :
          // ProjectAbs ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false );
          ProjectAbs ();
          virtual ~ProjectAbs () {}
          virtual bool create () override;
          virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;

        protected :
          QString name;
          QString path;
          QString type;
          QString resource;
             bool verboseMode;
          bool createDir () override;
          virtual bool createProjectFiles () override;
          virtual bool createStructDir () override { return true; }
          virtual bool createResourceFiles () override { return true; }
      };
    }
  }
}

#endif // PROJECTABS_H
