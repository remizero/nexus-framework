#include "NexusBuilderUtils.h"


using namespace NSLIB_BUILDER;


bool NexusBuilderUtils::createDirectory ( const QString &projectPath, const QString &projectName, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QString newPathDir = projectDir.filePath ( projectName );
    qDebug () << "newPathDir: " << newPathDir;
    if ( projectDir.mkpath ( newPathDir ) ) {

      if ( verboseMode ) {

        qDebug () << "Creado directorio de proyecto: " << newPathDir;
      }
    } else {

      qDebug () << "Error al crear el directorio de proyecto: " << newPathDir;
    }
    done = true;

  } else {

    qDebug () << "El directorio de proyecto ya existe: " << projectDir.path ();
  }
  return done;
}

QStringList NexusBuilderUtils::getClause ( QStringList stringLines, QString clause ) {

  bool found = false;
  // QString sourcesClause = "SOURCES +=";
  for ( int i = 0; i < stringLines.size (); ++i ) {

    if ( !found ) {

      qDebug () << stringLines.at ( i );
      if ( stringLines.at ( i ).contains ( clause ) ) {

        // sourcesClause = line;
        qDebug () << "CONTIENE LA CLAUSULA";
        found = true;
      }
    } else {

      if ( !stringLines.isEmpty () ) {

        qDebug () << stringLines.at ( i );
      }
    }
  }
}

QString NexusBuilderUtils::loadProTemplate ( const QString &resourcePath ) {

  QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( resourcePath + "pro.template" );
  if ( ioDeviceFile ) {

    QTextStream in ( ioDeviceFile );
    QString proTemplate = in.readAll ();
    ioDeviceFile->close ();
    return proTemplate;

  } else {

    return QString ( "" );
  }
}

QString NexusBuilderUtils::normalizeProjectName ( const QString &projectName ) {

  qDebug () << "Entrando por normalizeProjectName.";
  QString normalizedProjectName = projectName;
  int nexusIndex = projectName.indexOf ( "nexus", 0, Qt::CaseInsensitive );
  if ( nexusIndex != -1 && nexusIndex + 5 < projectName.length () ) {

    QString afterNexus = projectName.mid ( nexusIndex + 5 );
    normalizedProjectName = projectName.left ( nexusIndex + 5 ) + afterNexus.at ( 0 ).toUpper () + afterNexus.mid ( 1 );

  } else if ( !projectName.contains ( "nexus", Qt::CaseInsensitive ) ) {

    normalizedProjectName = QString ( "nexus" ) + projectName.at ( 0 ).toUpper () + projectName.mid ( 1 );
  }
  return normalizedProjectName;
}

QStringList NexusBuilderUtils::stringToLines ( QString content ) {

  return content.split ( "\n", Qt::SkipEmptyParts );
}



















bool NexusBuilderUtils::createProFile ( const QString &projectName ) {

  QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( projectName + ".pro", QIODevice::WriteOnly | QIODevice::Text );
  if ( ioDeviceFile ) {

    QTextStream out ( ioDeviceFile );
    out << "TARGET = " << projectName << "\n";
    ioDeviceFile->close ();
    qDebug () << "Created .pro file: " << projectName;
    return true;

  } else {

    qDebug () << "Failed to create .pro file: " << projectName;
    return false;
  }
}

void NexusBuilderUtils::createProFileFromTemplate ( const QString &projectPath, const QString &projectName, const QString &proTemplate ) {

  QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( projectPath + projectName + ".pro", QIODevice::WriteOnly | QIODevice::Text );
  if ( ioDeviceFile ) {

    QTextStream out ( ioDeviceFile );
    out << proTemplate.arg ( projectName );
    ioDeviceFile->close ();
    qDebug () << "Created .pro file: " << projectName;

  } else {

    qDebug () << "Failed to create .pro file: " << projectName;
  }
}

QString NexusBuilderUtils::getQmakeBuildersPath () {

  // FIXME El valor de esta ruta debe ser la ruta donde estará instalado el framework.
  QString qmakeBuildersPath = QCoreApplication::applicationDirPath ();
  qmakeBuildersPath = qmakeBuildersPath.left ( qmakeBuildersPath.length () - 10 ) + QDir::separator () + QString ( "qmakeBuilders" );
  return qmakeBuildersPath;
}

QString NexusBuilderUtils::getCopyFiles ( const QString &projecType ) {

  switch ( NexusBuilder::stringToProjectId ( projecType ) ) {

    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :

      return "copyBinaries.prf";
      break;

    case NexusBuilder::PLUGIN :

      return "copyPlugins.prf";
      break;

    case NexusBuilder::SHARE :
    case NexusBuilder::STATIC :

      return "copyLibraries.prf";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::getDeploymentRules ( const QString &projecType ) {

  switch ( NexusBuilder::stringToProjectId ( projecType ) ) {

    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :

      return "deploymentRulesBin.prf";
      break;

    case NexusBuilder::PLUGIN :
    case NexusBuilder::SHARE :
    case NexusBuilder::STATIC :

      return "deploymentRulesLib.prf";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::getProjectConfiguration ( const QString &projecType ) {

  switch ( NexusBuilder::stringToProjectId ( projecType ) ) {

    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :

      return "projectBinConfiguration.prf";
      break;

    case NexusBuilder::PLUGIN :

      return "projectLibPluginConfiguration.prf";
      break;

    case NexusBuilder::SHARE :

      return "projectLibShareConfiguration.prf";
      break;

    case NexusBuilder::STATIC :

      return "projectLibStaticConfiguration.prf";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::normalizeProjectFileContent ( const QString &proTemplate, const QString &projectName, const QString &projecType ) {

  QString modifiedTemplate = proTemplate;
  QStringList contentToken = {
    "{{projectName}}",
    "{{projectConfiguration}}",
    "{{copyFiles}}",
    "{{deploymentRules}}",
    "{{pathQmakeBuilders}}",
    "{{namespace}}",
    "{{include_guard}}",
    "{{global.h}}", // TODO Como obtener el nombre de la libraría xxxx_global.h
    "{{prefix}}", // TODO Como obtener el nombre para el prefix. Una estrategia podría ser {{projectName}}Resources
    "{{resourcesFileName}}", // TODO Como obtener el nombre del archivo de recursos y modificarlo dentro del archivo export.def.
    "PLUGIN", "MACROEXPORT", "CLASSNAME", "CLASSDEFINITION", "{{projectName}}" };
  for ( const QString &valor : contentToken ) {

    if ( valor.compare ( "{{projectName}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, projectName );

    } else if ( valor.compare ( "{{projectConfiguration}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getProjectConfiguration ( projecType ) );

    } else if ( valor.compare ( "{{copyFiles}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getCopyFiles ( projecType ) );

    } else if ( valor.compare ( "{{deploymentRules}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getDeploymentRules ( projecType ) );

    } else if ( valor.compare ( "{{pathQmakeBuilders}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getQmakeBuildersPath () );

    } else if ( valor.compare ( "{{namespace}}" ) == 0 ) {

      QString aux = projectName;
      aux [ 0 ] = aux [ 0 ].toUpper ();
      modifiedTemplate.replace ( valor, aux );

    } else if ( valor.compare ( "{{include_guard}}" ) == 0 ) {

      QString aux = projectName;
      modifiedTemplate.replace ( valor, aux.toUpper () );

    } else if ( valor.compare ( "PLUGIN" ) == 0 ) {

      QString aux = projectName;
      aux [ 0 ] = aux [ 0 ].toUpper ();
      modifiedTemplate.replace ( valor, aux );

    } else if ( valor.compare ( "MACROEXPORT" ) == 0 ) {

      QString aux = projectName;
      modifiedTemplate.replace ( valor, aux.toUpper () );

    } else if ( valor.compare ( "CLASSNAME" ) == 0 ) {

      QString aux = projectName;
      aux [ 0 ] = aux [ 0 ].toUpper ();
      modifiedTemplate.replace ( valor, aux );

    } else if ( valor.compare ( "CLASSDEFINITION" ) == 0 ) {

      QString aux = projectName;
      modifiedTemplate.replace ( valor, aux.toUpper () );

    } else if ( valor.compare ( "{{project}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, projectName );
    }
  }
  return proTemplate;
}
