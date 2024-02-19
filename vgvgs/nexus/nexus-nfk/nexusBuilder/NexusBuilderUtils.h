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
#include <QMap>
#include <QString>
#include <QStringList>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT NexusBuilderUtils {

        public :
          static bool createDirectory ( const QString &projectPath, const QString &projectName, bool verboseMode = false );
          static QStringList findFiles ( const QString &searchPath, const QString &filters );
          static QStringList getClause ( QStringList stringLines, QString clause );
          static QString getCopyFiles ( NexusBuilder::ProjectId projectType );
          static QString getDeploymentRules ( NexusBuilder::ProjectId projectType );
          static QString getProjectConfiguration ( NexusBuilder::ProjectId projectType );
          static QString getQmakeBuildersPath ();
          static QStringList insertLinesFromList ( QStringList codeLines, QString token, QStringList fileList );
          static QString loadFileContent ( const QString &resourcePath );
          static QString normalizeExportName ( const QString &prefix );
          static QString normalizeGlobalName ( const QString &prefix, const QString &fileName );
          static QString normalizeProjectFileContent ( const QString &proTemplate, const QString &projectName, NexusBuilder::ProjectId projectType );
          static QString normalizeProjectName ( const QString &projectName );
          static QString normalizeResourceName ( const QString &resourceName );
          static QMap<QString, QStringList> readResourcesRecursively ( const QString &path, const QStringList &currentDirList );
          static QStringList stringToLines ( QString content );
        };
      }
    }
  }

#endif // NEXUSBUILDERUTILS_H
