#include "AppProject.h"


using namespace NSLIB_BUILDER;


AppProject::AppProject ( QObject *parent ) : ProjectAbs ( parent ) {

  this->configBuilder = new ConfigBuilder ();
  this->exportsBuilder = new ExportsBuilder ();
  this->mainBuilder = new MainBuilder ();
  this->qssBuilder = new QssBuilder ();
  this->resourcesBuilder = new ResourcesBuilder ();
}

void AppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projectType, verboseMode );
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

  ClassBuilder *classBuilder = new ClassBuilder ( "Dinosaurio", NexusBuilder::FileClasses::HEADERSONLY );

  AttributeBuilder *attributeBuilder = new AttributeBuilder ( "number", "int", false, false, "0" );
  attributeBuilder->setAccessibility ( NexusBuilder::Accessibility::PRIVATE );
  // attributeBuilder->setDefaultValue ( 0 );
  // attributeBuilder->setName ( "number" );
  // attributeBuilder->setType ( "int" );
  classBuilder->setAttributeList ( attributeBuilder );

  MethodBuilder *methodBuilder = new MethodBuilder ();
  methodBuilder->setAccessibility ( NexusBuilder::Accessibility::PROTECTED );
  methodBuilder->setBody ( "// TODO Incluir código aquí." );
  methodBuilder->setImplementedIn ( true );
  methodBuilder->setIsPointer ( true );
  methodBuilder->setName ( "method_1" );
  methodBuilder->setType ( "QString" );

  ParamBuilder *paramBuilder = new ParamBuilder ( "number", "int", false, false, "0" );
  // paramBuilder->setDefaultValue ( "0" );
  // paramBuilder->setName ( "number" );
  // paramBuilder->setType ( "int" );
  methodBuilder->setParamList ( paramBuilder );

  ParamBuilder *paramBuilder_1 = new ParamBuilder ( "number", "int", false, false );
  // paramBuilder_1->setName ( "string" );
  // paramBuilder_1->setType ( "QString" );
  methodBuilder->setParamList ( paramBuilder_1 );
  classBuilder->setMethodList ( methodBuilder );

  MethodBuilder *methodBuilder_1 = new MethodBuilder ();
  methodBuilder_1->setAccessibility ( NexusBuilder::Accessibility::PRIVATE );
  methodBuilder_1->setBody ( "// TODO Incluir código aquí." );
  methodBuilder_1->setImplementedIn ( true );
  methodBuilder_1->setIsPointer ( false );
  methodBuilder_1->setName ( "method_2" );
  methodBuilder_1->setType ( "void" );
  classBuilder->setMethodList ( methodBuilder_1 );

  MethodBuilder *methodBuilder_2 = new MethodBuilder ();
  methodBuilder_2->setAccessibility ( NexusBuilder::Accessibility::PUBLIC );
  methodBuilder_2->setBody ( "// TODO Incluir código aquí." );
  methodBuilder_2->setImplementedIn ( false );
  methodBuilder_2->setIsPointer ( false );
  methodBuilder_2->setName ( "method_3" );
  methodBuilder_2->setType ( "void" );
  classBuilder->setMethodList ( methodBuilder_2 );

  classBuilder->setNamespaceList ( "namespace_1" );
  classBuilder->setNamespaceList ( "namespace_2" );
  classBuilder->build ();
  classBuilder->toFile ( this->path );

  return done;
}

bool AppProject::createProjectFiles () {

  bool done = false;
  if ( this->isInitialized () ) {

    for ( const QString &templeteFile : this->projectFileList ) {

      QString projectFile = templeteFile;
      projectFile.remove ( ".template" );
      if ( templeteFile.contains ( "main.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    this->mainBuilder->build ( this->resource + templeteFile, this->projectType ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "config.xml" ) ) {

        if ( !( done = NSLIB_UTILS::Xml::save ( this->path + QDir::separator () + "resources" + QDir::separator () + projectFile,
                                                this->configBuilder->build ( this->resource + templeteFile, this->normalizedProjectName, this->projectType ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "style.qss" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + "resources" + QDir::separator () + projectFile,
                                                    this->qssBuilder->build ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "CommandProcessor.h" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "CommandProcessor.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "export.def" ) ) {

        QStringList resourcesList = NexusBuilderUtils::findFiles ( this->path, "*.qrc" );
        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    this->exportsBuilder->build ( this->resource + templeteFile, resourcesList ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.h" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "MainWindow.ui" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "RegisterClasses.h" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + this->normalizedProjectName + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "RegisterClasses.cpp" ) ) {

        if ( !( done = NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + this->normalizedProjectName + projectFile,
                                                    NexusBuilderUtils::loadFileContent ( this->resource + templeteFile ) ) ) ) {

          break;
        }
      } else if ( templeteFile.contains ( "resources.qrc" ) ) {

        QStringList initialDirList;
        QMap<QString, QStringList> resourcesMap = NexusBuilderUtils::readResourcesRecursively ( this->path + QDir::separator () + "resources" + QDir::separator (), initialDirList );
        projectFile = this->normalizedProjectName + projectFile.at ( 0 ).toUpper () + projectFile.mid ( 1 );
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
