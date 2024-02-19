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
#include "Strings.h"

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


  namespace NS_VGVGS {

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
            ProjectAbs ( QObject *parent = nullptr );
            virtual ~ProjectAbs () {}
            void init ( QString projectName, QString projectPath, QString projectType, bool verboseMode = false ) override;
            bool createProjectDir () override;
            bool createProFile () override;
            virtual bool createDirStruct () override { return true; }
            virtual bool createProjectFiles () override { return true; }
            virtual bool createCommandFiles () override { return true; }
            virtual bool createResourceFiles () override { return true; }
            Status getStatus () const;
            bool isInitialized () const;

          protected :
                        QStringList dirList;
                            QString name;
                            QString normalizedProjectName;
                            QString path;
                            QString prefix;
            NexusBuilder::ProjectId projectType;
                        QStringList projectFileList;
                            QString resource;
                             Status status;
                               bool verboseMode;
                         ProBuilder *proBuilder;
        };
      }
    }
  }

#endif // PROJECTABS_H
