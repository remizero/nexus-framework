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
#include <QStringList>
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ProjectAbs : public ProjectInterface {

          Q_INTERFACES ( NSLIB_NEXUSBUILDER::ProjectInterface )

        public :
          ProjectAbs ();
          virtual ~ProjectAbs () {}
          virtual void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;

          bool createProjectDir () override;
          bool createProFile () override;
          virtual bool createDirStruct () override { return true; }
          virtual bool createProjectFiles () override { return true; }
          virtual bool createCommandFiles () override { return true; }
          virtual bool createResourceFiles () override { return true; }

        protected :
              QString name;
              QString path;
              QString type;
              QString resource;
          QStringList contentToken;
          QStringList fileNameToken;
                 bool verboseMode;
          bool copyFiles ( QStringList resourceList, QString resoursePath, QString destinyPath = "" );
          bool createDir ( QStringList dirList );
          QString normalizeFileName ( QString fileName );
          QString normalizeContentFile ( QString fileContent );
      };
    }
  }
}

#endif // PROJECTABS_H
