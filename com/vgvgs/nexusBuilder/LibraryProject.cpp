#include "LibraryProject.h"


using namespace NSLIB_BUILDER;


LibraryProject::LibraryProject ( QObject *parent ) : ProjectAbs ( parent ) {

  this->globalBuilder = new GlobalBuilder ();
  this->resourcesBuilder = new ResourcesBuilder ();
}

void LibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projectType, verboseMode );
}

bool LibraryProject::createDirStruct () {

  bool done = false;
  QDir projectDir ( this->path );
  if ( projectDir.exists () ) {

    for ( const QString &dir : this->dirList ) {

      if ( !( done = NexusBuilderUtils::createDirectory ( this->path, dir, this->verboseMode ) ) ) {

        break;
      }
    }
  } else {

    qDebug () << "El directorio de proyecto no existe o no se encuentra: " << projectDir.path ();
  }
  return done;
}

bool LibraryProject::createProjectFiles () {

  bool done = false;
  if ( this->isInitialized () ) {

    for ( const QString &templeteFile : this->projectFileList ) {

      QString projectFile = templeteFile;
      projectFile.remove ( ".template" );
      if ( templeteFile.contains ( "Version.h" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    this->versionBuilder->build ( this->resource + templeteFile, this->name, projectFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "Version.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    this->versionBuilder->build ( this->resource + templeteFile, this->name, projectFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "global.h" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + NexusBuilderUtils::normalizeGlobalName ( this->name, projectFile ),
                                                    this->globalBuilder->build ( this->resource + templeteFile, this->name ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "export.def" ) ) {

        QStringList resourcesList = NexusBuilderUtils::findFiles ( this->path, "*.qrc" );
        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    this->exportsBuilder->build ( this->resource + templeteFile, resourcesList ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "resources.qrc" ) ) {

        QStringList initialDirList;
        QMap<QString, QStringList> resourcesMap = NexusBuilderUtils::readResourcesRecursively ( this->path + QDir::separator () + "resources" + QDir::separator (), initialDirList );
        projectFile = this->prefix + projectFile.at ( 0 ).toUpper () + projectFile.mid ( 1 );
        if ( !( done = NSLIB_UTILS::Xml::save ( this->path + QDir::separator () + projectFile,
                                                this->resourcesBuilder->build ( this->resource + templeteFile, resourcesMap ) ) ) ) {

          break;
        }
      }
    }
  } else {

    qDebug () << "La clase AppProject no ha sido inicializa correctamente. Línea 76.";
  }
  return done;
}
