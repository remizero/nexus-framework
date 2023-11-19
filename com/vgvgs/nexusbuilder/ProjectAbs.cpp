#include "ProjectAbs.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//ProjectAbs::ProjectAbs ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  name ( projectName ),
//  path ( projectPath ),
//  type  ( projecType  ),
//  verboseMode ( verboseMode ) {}
ProjectAbs::ProjectAbs () {}

bool ProjectAbs::create () {

  return this->createDir ();
//  if ( this->createDir () ) {

//    if ( projecType.compare ( "console" ) == 0 ) {



//    } else if ( projecType.compare ( "gui" ) == 0 ) {



//    } else if ( projecType.compare ( "plugin" ) == 0 ) {


//    }
//    if ( this->createStructDir ( projectPath + projectName + QDir::separator (), verboseMode ) ) {

//      if ( this->createProjectFiles () ) {

//        if ( this->createResourcesFile ( projectName, projectPath + projectName + QDir::separator (), verboseMode ) ) {

//        }
//      }
//    }
  //  }
  }

void ProjectAbs::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  this->name        = projectName;
  this->path        = projectPath;
  this->type        = projecType;
  this->verboseMode = verboseMode;
}

bool ProjectAbs::createDir () {

  bool done = false;
  QDir projectDir ( this->path.append ( this->name ) );
  if ( !projectDir.exists () ) {

    if ( projectDir.mkpath ( projectDir.path () ) ) {

//      done = true;
      if ( this->verboseMode ) {

        qDebug () << "Creado directorio de proyecto: " << projectDir.path ();
      }
      done = this->createProjectFiles ();

    } else {

      qDebug () << "Error al crear el directorio de proyecto.";
    }
  } else {

    qDebug () << "El directorio de proyecto ya existe: " << projectDir.path ();
  }
  return done;
}

bool ProjectAbs::createProjectFiles () {

  bool done = false;
  //const QString projectPath = this->path + this->name + QDir::separator ();
  const QString projectPath = this->path;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QStringList resourceList = { "projectNameIdentifier.pro" };

    for ( const QString &resourceName : resourceList ) {

      QFile resourceFile ( this->resource + resourceName );
      if ( resourceFile.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {

        QTextStream in ( &resourceFile );
        QString fileContent = in.readAll ();
        resourceFile.close ();
        fileContent.replace ( "projectNameIdentifier", this->name );

        QString fileName = resourceName;
        fileName.replace ( "projectNameIdentifier", this->name );
        QString destinationPath = projectPath + fileName;
        QFile newProFile ( destinationPath );
        if ( newProFile.open ( QIODevice::WriteOnly | QIODevice::Text ) ) {

          QTextStream out ( &newProFile );
          out << fileContent;
          newProFile.close ();
          if ( verboseMode ) {

            qDebug () << "Copiando archivo en directorio de proyecto: " << destinationPath;
          }
          done = true;
        } else {

          qDebug () << "No se pudo crear el archivo de proyecto .pro.";
          done = false;
          break;
        }
      } else {

        qDebug () << "No se pudo abrir el archivo de recursos.";
        done = false;
        break;
      }
    }
  } else {

    qDebug () << "El directorio de proyecto no existe o no se encuentra: " << projectDir.path ();
  }
  return done;
}
