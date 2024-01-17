#include "AppProject.h"


using namespace NSLIB_BUILDER;


AppProject::AppProject ( QObject *parent ) : ProjectAbs ( parent ) {

  this->configBuilder = new ConfigBuilder ();
  this->exportsBuilder = new ExportsBuilder ();
  this->mainBuilder = new MainBuilder ();
  this->resourcesBuilder = new ResourcesBuilder ();
}

void AppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projectType, verboseMode );
}

bool AppProject::createProjectFiles () {

  bool done = false;
  if ( this->isInitialized () ) {

    for ( const QString &templeteFile : this->projectFileList ) {

      QString projectFile = templeteFile;
      projectFile.remove ( ".template" );
      if ( templeteFile.contains ( "main.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( this->mainBuilder->build ( this->resource + templeteFile, this->normalizedProjectName, this->projectType ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "config.xml" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + "resources/" + projectFile,
                                                  QVariant::fromValue ( this->configBuilder->build ( this->resource + templeteFile, this->normalizedProjectName, this->projectType ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "CommandProcessor.h" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "CommandProcessor.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "export.def" ) ) {

        QStringList resourcesList = NexusBuilderUtils::findQrcFiles ( this->path );
        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( this->exportsBuilder->build ( this->resource + templeteFile, resourcesList ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.h" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.ui" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "RegisterClasses.h" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "RegisterClasses.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Files::save ( this->path + QDir::separator () + projectFile,
                                                  QVariant::fromValue ( NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "resources.qrc" ) ) {

        QStringList initialDirList;
        QMap<QString, QStringList> resourcesMap = NexusBuilderUtils::readResourcesRecursively ( this->path + QDir::separator () + "resources/", initialDirList );
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

bool AppProject::createDirStruct () {

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
