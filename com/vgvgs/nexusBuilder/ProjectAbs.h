#ifndef PROJECTABS_H
#define PROJECTABS_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilderUtils.h"
#include "ProjectInterface.h"
#include "builders/ProBuilder.h"

// Librerías Externas
// External Libraries
#include "Files.h"

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

        class BUILDER_EXPORT ProjectAbs : public QObject, public ProjectInterface {

            Q_INTERFACES ( NSLIB_BUILDER::ProjectInterface )
            Q_OBJECT

          public :
            enum Status {

              initialized,
              notInitialized
            };
            Q_ENUM ( Status )
            ProjectAbs ( QObject *parent = nullptr );
            virtual ~ProjectAbs () {}
            void init ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false ) override;
            bool createProjectDir () override; // LISTO
            // bool createProFile () override;
            // virtual bool createDirStruct () override { return true; }
            // virtual bool createProjectFiles () override { return true; }
            // virtual bool createCommandFiles () override { return true; }
            // virtual bool createResourceFiles () override { return true; }
            Status getStatus () const;
            bool isInitialized () const;

          protected :
                QString name;
                QString normalizedProjectName;
                QString path;
                QString prefix;
                QString type;
                QString resource;
            QStringList contentToken;
            QStringList fileNameToken;
                 Status status;
                   bool verboseMode;
             ProBuilder *proBuilder;
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
