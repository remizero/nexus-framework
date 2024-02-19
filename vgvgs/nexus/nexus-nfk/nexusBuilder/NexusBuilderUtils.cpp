#include "NexusBuilderUtils.h"


using namespace NSLIB_BUILDER;


bool NexusBuilderUtils::createDirectory ( const QString &projectPath, const QString &projectName, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QString newPathDir = projectDir.filePath ( projectName );
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

QStringList NexusBuilderUtils::findFiles ( const QString &searchPath, const QString &filters ) {

  QStringList filesFound;
  QDir searchDir ( searchPath );
  QStringList filterList;
  filterList << filters;
  searchDir.setNameFilters ( filterList );
  QFileInfoList fileInfoList = searchDir.entryInfoList ( QDir::Files );
  for ( const QFileInfo &fileInfo : fileInfoList ) {

    filesFound.append ( fileInfo.absoluteFilePath () );
  }
  return filesFound;
}

QStringList NexusBuilderUtils::getClause ( QStringList stringLines, QString clause ) {

  bool found = false;
  // QString sourcesClause = "SOURCES +=";
  for ( int i = 0; i < stringLines.size (); ++i ) {

    if ( !found ) {

      // qDebug () << stringLines.at ( i );
      if ( stringLines.at ( i ).contains ( clause ) ) {

        // sourcesClause = line;
        // qDebug () << "CONTIENE LA CLAUSULA";
        found = true;
      }
    } else {

      if ( !stringLines.isEmpty () ) {

        // qDebug () << stringLines.at ( i );
      }
    }
  }
  return stringLines;
}

QString NexusBuilderUtils::getCopyFiles ( NexusBuilder::ProjectId projectType ) {

  switch ( projectType ) {

    case NexusBuilder::BLANKAPP :
    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :
    case NexusBuilder::SIMPLEGUI :

      return "copyBinaries";
      break;

    case NexusBuilder::BLANKLIBRARY :

      return "copyPlugins";
      break;

    case NexusBuilder::PLUGIN :

      return "copyPlugins";
      break;

    case NexusBuilder::SHARE :
    case NexusBuilder::STATIC :

      return "copyLibraries";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::getDeploymentRules ( NexusBuilder::ProjectId projectType ) {

  switch ( projectType ) {

    case NexusBuilder::BLANKAPP :
    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :
    case NexusBuilder::SIMPLEGUI :

      return "deploymentRulesBin";
      break;

    case NexusBuilder::BLANKLIBRARY :
    case NexusBuilder::PLUGIN :
    case NexusBuilder::SHARE :
    case NexusBuilder::STATIC :

      return "deploymentRulesLib";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::getProjectConfiguration ( NexusBuilder::ProjectId projectType ) {

  switch ( projectType ) {

    case NexusBuilder::BLANKAPP :
    case NexusBuilder::CONSOLE :
    case NexusBuilder::GUI :
    case NexusBuilder::NEXUS :
    case NexusBuilder::SIMPLEGUI :

      return "projectBinConfiguration";
      break;

    case NexusBuilder::BLANKLIBRARY :

      return "projectLibPluginConfiguration";
      break;

    case NexusBuilder::PLUGIN :

      return "projectLibPluginConfiguration";
      break;

    case NexusBuilder::SHARE :

      return "projectLibShareConfiguration";
      break;

    case NexusBuilder::STATIC :

      return "projectLibStaticConfiguration";
      break;

    default :
      return "";
      break;
  }
}

QString NexusBuilderUtils::getQmakeBuildersPath () {

  // FIXME El valor de esta ruta debe ser la ruta donde estará instalado el framework.
  QString qmakeBuildersPath = QCoreApplication::applicationDirPath ();
  qmakeBuildersPath = qmakeBuildersPath.left ( qmakeBuildersPath.length () - 10 ) + QDir::separator () + QString ( "qmakeBuilders" );
  return qmakeBuildersPath;
  }

QStringList NexusBuilderUtils::insertLinesFromList ( QStringList codeLines, QString token, QStringList fileList ) {

  if ( fileList.length () > 0 ) {

    int index = -1;
    int factor = 0;
    index = codeLines.indexOf ( token );
    for ( const QString &file : fileList ) {

      QStringList fileSplit = file.split ( QDir::separator () );
      codeLines.insert ( index + ++factor, "  " + fileSplit.last () + " \\" );
    }
    QString lastInsertedLine = codeLines.at ( index + factor );
    lastInsertedLine.chop ( 2 );
    codeLines.replace ( index + factor, lastInsertedLine );
  }
  return codeLines;
}

QString NexusBuilderUtils::loadFileContent ( const QString &resourcePath ) {

  QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( resourcePath );
  if ( ioDeviceFile ) {

    QTextStream in ( ioDeviceFile );
    QString fileContent = in.readAll ();
    ioDeviceFile->close ();
    return fileContent;

  } else {

    return QString ( "" );
  }
}

QString NexusBuilderUtils::normalizeExportName ( const QString &prefix ) {

  return prefix.toUpper () + "_EXPORT";
}

QString NexusBuilderUtils::normalizeGlobalName ( const QString &prefix, const QString &fileName ) {

  return prefix.at ( 0 ).toUpper () + prefix.mid ( 1 ) + "_" + fileName;
}

QString NexusBuilderUtils::normalizeProjectFileContent ( const QString &proTemplate, const QString &projectName, NexusBuilder::ProjectId projectType ) {

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

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getProjectConfiguration ( projectType ) );

    } else if ( valor.compare ( "{{copyFiles}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getCopyFiles ( projectType ) );

    } else if ( valor.compare ( "{{deploymentRules}}" ) == 0 ) {

      modifiedTemplate.replace ( valor, NexusBuilderUtils::getDeploymentRules ( projectType ) );

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
  return modifiedTemplate;
}

QString NexusBuilderUtils::normalizeProjectName ( const QString &projectName ) {

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

QString NexusBuilderUtils::normalizeResourceName ( const QString &resourceName ) {

  QString resourceNameAux = resourceName;
  if ( resourceNameAux.isEmpty () ) {

    resourceNameAux = "/mainapp";

  } else {

    QStringList resourceList = resourceNameAux.split ( "resources" );
    resourceNameAux = "/resources"  + resourceList.at ( resourceList.length () - 1 );
  }
  return resourceNameAux;
}

QMap<QString, QStringList> NexusBuilderUtils::readResourcesRecursively ( const QString &path, const QStringList &currentDirList ) {

    QMap<QString, QStringList> prefixFileMap;
    QDir dir ( path );
    QStringList filters;
    filters << "*";
    dir.setNameFilters ( filters );
    QFileInfoList fileInfoList = dir.entryInfoList ( QDir::Files );
    foreach ( const QFileInfo &fileInfo, fileInfoList ) {

      QString filePath = fileInfo.absoluteFilePath ();
      QString currentPath = currentDirList.join ( "/" );
      if ( currentPath.isEmpty () ) {

        currentPath = "/mainapp";

      } else {

        currentPath = "/resources/" + currentPath;
      }
      if ( !prefixFileMap.contains ( currentPath ) ) {

        prefixFileMap [ currentPath ] = QStringList ();
      }
      prefixFileMap [ currentPath ].append ( filePath );
    }
    QFileInfoList folderInfoList = dir.entryInfoList ( QDir::Dirs | QDir::NoDotAndDotDot );
    foreach ( const QFileInfo &folderInfo, folderInfoList ) {

      QStringList updatedDirList = currentDirList;
      updatedDirList.append ( folderInfo.fileName () );
      QString updatedPath = updatedDirList.join ( "/" );
      QMap<QString, QStringList> subMap = readResourcesRecursively ( folderInfo.absoluteFilePath (), updatedDirList );
      // Merge subMap into prefixFileMap
      for ( auto it = subMap.constBegin (); it != subMap.constEnd (); ++it ) {

        if ( !prefixFileMap.contains ( it.key () ) ) {

          prefixFileMap [ it.key () ] = QStringList ();
        }
        prefixFileMap [ it.key () ].append ( it.value () );
      }
    }
    return prefixFileMap;
}

QStringList NexusBuilderUtils::stringToLines ( QString content ) {

  return content.split ( "\n" );
}
