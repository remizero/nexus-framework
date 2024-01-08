#ifndef PROJECTABS_H
#define PROJECTABS_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"
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
#include <QObject>
#include <QStringList>
#include <QVariant>

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

              INITIALIZED,
              NOT_INITIALIZED
            };
            Q_ENUM ( Status )
            ProjectAbs ( QObject *parent = nullptr ); // (LISTO)
            virtual ~ProjectAbs () {} // (LISTO)
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override; // (LISTO)
            bool createProjectDir () override; // LISTO
            bool createProFile () override; // (LISTO)
            virtual bool createDirStruct () override { return true; }
            virtual bool createProjectFiles () override { return true; }
            // virtual bool createCommandFiles () override { return true; }
            // virtual bool createResourceFiles () override { return true; }
            Status getStatus () const; // (LISTO)
            bool isInitialized () const; // (LISTO)

          protected :
                        QStringList dirList;
                            QString name; // (LISTO)
                            QString normalizedProjectName; // (LISTO)
                            QString path; // (LISTO)
                            QString prefix; // (LISTO)
            NexusBuilder::ProjectId projectType; // (LISTO)
                        QStringList projectFileList; // (LISTO)
                            QString resource; // (LISTO)
                        QStringList contentToken;
                        QStringList fileNameToken;
                             Status status; // (LISTO)
                               bool verboseMode; // (LISTO)
                         ProBuilder *proBuilder; // (LISTO)
            // bool copyFiles ( QStringList resourceList, QString resoursePath, QString destinyPath = "" );
            // bool createDir ( QStringList dirList );
            QString normalizeFileName ( QString fileName ); // (LISTO)
            // QString normalizeContentFile ( QString fileContent );
        };
      }
    }
  }
}

#endif // PROJECTABS_H
