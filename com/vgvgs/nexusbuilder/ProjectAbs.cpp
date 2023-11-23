#include "ProjectAbs.h"


using namespace NSLIB_NEXUSBUILDER;


ProjectAbs::ProjectAbs () {

  this->verboseMode = false;
}

void ProjectAbs::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  this->name        = projectName;
  this->path        = projectPath;
  this->type        = projecType;
  this->verboseMode = verboseMode;
  this->fileNameToken << "project" << "Plugin" << "Share";
  this->contentToken << "PLUGIN" << "MACROEXPORT" << "CLASSNAME" << "CLASSDEFINITION" << "{{project}}";
  // MACROEXPORT     debe ser remplazado capitalizando toda la palabra.
  // CLASSNAME       debe ser remplazado capitalizando la primera letra.
  // CLASSDEFINITION debe ser remplazado capitalizando toda la palabra.
}

bool ProjectAbs::copyFiles ( QStringList resourceList, QString resoursePath, QString destinyPath ) {

  bool done = false;
  const QString projectPath = this->path;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    for ( const QString &resourceName : resourceList ) {

      QFile resourceFile ( resoursePath + resourceName );
      if ( resourceFile.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {

        QTextStream in ( &resourceFile );
        QString fileContent = in.readAll ();
        resourceFile.close ();
        fileContent = this->normalizeContentFile ( fileContent );

        QString fileName = this->normalizeFileName ( resourceName );
        QString destinationPath = projectPath + QDir::separator ();
        if ( destinyPath.isEmpty () ) {

          destinationPath.append ( fileName );

        } else {

          destinationPath.append ( destinyPath + QDir::separator () + fileName );
        }
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

          qDebug () << "No se pudo crear el archivo de proyecto " + destinationPath;
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

bool ProjectAbs::createDir ( QStringList dirList ) {

  bool done = false;
  QDir projectDir ( this->path );
  if ( projectDir.exists () ) {

    for ( const QString &dir : dirList ) {

      QString newPathDir = projectDir.filePath ( dir );
      if ( projectDir.mkpath ( newPathDir ) ) {

        if ( this->verboseMode ) {

          qDebug () << "Creado directorio de proyecto: " << newPathDir;
        }
      } else {

        qDebug () << "Error al crear el directorio de proyecto: " << newPathDir;
      }
    }
    done = true;

  } else {

    qDebug () << "El directorio de proyecto no existe o no se encuentra: " << projectDir.path ();
  }
  return done;
  }

QString ProjectAbs::normalizeFileName ( QString fileName ) {

  for ( const QString &valor : this->fileNameToken ) {

    if ( fileName.contains ( valor ) ) {

      fileName.replace ( valor, this->name );
      fileName [ 0 ] = fileName [ 0 ].toUpper ();
      break;
    }
  }
  return fileName;
}

QString ProjectAbs::normalizeContentFile ( QString fileContent ) {

  for ( const QString &valor : this->contentToken ) {

    if ( valor.compare ( "PLUGIN" ) == 0 ) {

      QString aux = this->name;
      aux [ 0 ] = aux [ 0 ].toUpper ();
      fileContent.replace ( valor, aux );

    } else if ( valor.compare ( "MACROEXPORT" ) == 0 ) {

      QString aux = this->name;
      fileContent.replace ( valor, aux.toUpper () );

    } else if ( valor.compare ( "CLASSNAME" ) == 0 ) {

      QString aux = this->name;
      aux [ 0 ] = aux [ 0 ].toUpper ();
      fileContent.replace ( valor, aux );

    } else if ( valor.compare ( "CLASSDEFINITION" ) == 0 ) {

      QString aux = this->name;
      fileContent.replace ( valor, aux.toUpper () );

    } else if ( valor.compare ( "{{project}}" ) == 0 ) {

      fileContent.replace ( valor, this->name );
    }
  }
  return fileContent;
}

bool ProjectAbs::createProjectDir () {

  bool done = this->createDir ( { this->name } );
  if ( done ) {

    this->path.append ( this->name );
  }
  return done;
}

bool ProjectAbs::createProFile () {

  return this->copyFiles ( { "project.pro" }, this->resource );
}
