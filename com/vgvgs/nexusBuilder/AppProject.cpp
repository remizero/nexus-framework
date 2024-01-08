#include "AppProject.h"


using namespace NSLIB_BUILDER;


AppProject::AppProject ( QObject *parent ) : ProjectAbs ( parent ) {

  this->mainBuilder = new MainBuilder ();
  this->configBuilder = new ConfigBuilder ();
}

void AppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projectType, verboseMode );
}

bool AppProject::createProjectFiles () {

  // TODO Si projectType es de tipo BlankAppProject, solo se debe agregar un archivo main.cpp en blanco.
  // TODO Si projectType es de tipo ConsoleAppProject, solo se debe agregar CommandProcessor, RegisterClasses, el directorio commands y el archivo de recurso config.xml.
  // TODO Si projectType es de tipo GuiAppProject, solo se debe agregar un archivo main.cpp con MainWindow heredando de NexusMainWindow, sin capacidad de procesar comandos.
  // TODO Si projectType es de tipo NexusAppProject, solo se debe agregar un archivo main.cpp con las configuraciones de los proyectos de tipo Console y Gui.
  // TODO Si projectType es de tipo SimpleGuiAppProject, solo se debe agregar un archivo main.cpp con MainWindow simple heredado de Qt directamente.
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
