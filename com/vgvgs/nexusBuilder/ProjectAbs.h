#ifndef PROJECTABS_H
#define PROJECTABS_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDir>
#include <QStringList>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ProjectAbs : public ProjectInterface {

            Q_INTERFACES ( NSLIB_BUILDER::ProjectInterface )

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
}

#endif // PROJECTABS_H
