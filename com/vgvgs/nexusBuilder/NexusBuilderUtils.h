#ifndef NEXUSBUILDERUTILS_H
#define NEXUSBUILDERUTILS_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"

// Librerías Externas
// External Libraries
#include "Files.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QStringList>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT NexusBuilderUtils {

        public :
          static bool createProFile ( const QString &projectName );
          static void createProFileFromTemplate ( const QString &projectPath, const QString &projectName, const QString &proTemplate );




          // Los métodos que van quedando.
          static bool createDirectory ( const QString &projectPath, const QString &projectName, bool verboseMode = false );
          static QStringList getClause ( QStringList stringLines, QString clause );
          static QString getCopyFiles ( NexusBuilder::ProjectId projectType );
          static QString getDeploymentRules ( NexusBuilder::ProjectId projectType );
          static QString getProjectConfiguration ( NexusBuilder::ProjectId projectType );
          static QString getQmakeBuildersPath ();
          static QString loadFileContent ( const QString &resourcePath );
          static QString normalizeProjectFileContent ( const QString &proTemplate, const QString &projectName, NexusBuilder::ProjectId projectType );
          static QString normalizeProjectName ( const QString &projectName );
          static QStringList stringToLines ( QString content );

        };
      }
    }
  }
}

#endif // NEXUSBUILDERUTILS_H
