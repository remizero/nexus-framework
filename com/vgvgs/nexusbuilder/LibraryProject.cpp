#include "LibraryProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//LibraryProject::LibraryProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  ProjectAbs ( projectName, projectPath, projecType, verboseMode )
//{}
LibraryProject::LibraryProject () {}

bool LibraryProject::create () {

  return ProjectAbs::create ();
}

void LibraryProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projecType, verboseMode );
}

bool LibraryProject::createProjectFiles () {

  bool done = ProjectAbs::createProjectFiles ();
  if ( done ) {

    const QString projectPath = this->path + this->name + QDir::separator ();
    QDir projectDir ( projectPath );
    if ( projectDir.exists () ) {

      QStringList resourceList = {
        "main.cpp",
        "RegisterClasses.h",
        "RegisterClasses.cpp"
      };

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
  }
  return done;
}
