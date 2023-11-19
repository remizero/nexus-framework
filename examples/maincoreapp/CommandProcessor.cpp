#include "CommandProcessor.h"


CommandProcessor::CommandProcessor () {}

void CommandProcessor::processCommands ( QCommandLineParser &parser, QMap<QString, NAMESPACE_LIBRARY_CORE::CommandInterface *> commandMap ) {

  parser.addPositionalArgument ( "projectName", QCoreApplication::translate ( "main", "Project Name." ) );
  parser.addPositionalArgument ( "destination", QCoreApplication::translate ( "main", "Destination directory." ) );
  const QStringList optionList = parser.optionNames ();
  QString projecType;
  bool verboseMode = false;

  for ( const QString &option : optionList ) {

    if ( parser.isSet ( option ) ) {

      if ( ( option.compare ( "t" ) == 0 ) || ( option.compare ( "type" ) == 0 ) ) {

        projecType = parser.value ( option );
        if ( projecType.isEmpty () ) {

          qDebug () << "Se debe suministrar un tipo de aplicación: \"gui\" o \"console\".";
          return;
        }
      } else if ( ( option.compare ( "V" ) == 0 ) || ( option.compare ( "verbose" ) == 0 ) ) {

        verboseMode = true;
        qDebug () << "Verbose mode is enabled...";
        qDebug () << "\n";
      }

      NAMESPACE_LIBRARY_CORE::CommandInterface *command = commandMap.value ( option );
      if ( command ) {

        // TODO Analizar para que sirve exactamente esto?
        command->execute ();

      } else {

        qDebug () << "Comando no encontrado para la opción:" << option;
      }
    }
  }
  QStringList positionalArguments = parser.positionalArguments ();
  if ( !positionalArguments.isEmpty () ) {

    this->createProject ( positionalArguments.value ( 0 ), positionalArguments.value ( 1 ), projecType, verboseMode );

  } else {

    qDebug () << "Falta de argumentos.";
  }
}

void CommandProcessor::createProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  // Procesar argumentos y opciones según sea necesario
  qDebug () << "Nombre del proyecto: " << projectName;
  qDebug () << "Ruta del destino: " << projectPath;
  qDebug () << "Tipo de proyecto: " << projecType;

  if ( this->createDirProject ( projectName, projectPath, verboseMode ) ) {

    if ( projecType.compare ( "console" ) == 0 ) {



    } else if ( projecType.compare ( "gui" ) == 0 ) {



    } else if ( projecType.compare ( "plugin" ) == 0 ) {


    }
    if ( this->createStructDirProject ( projectPath + projectName + QDir::separator (), verboseMode ) ) {


    }
  }
}

bool CommandProcessor::createDirProject ( QString projectName, QString projectPath, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath.append ( projectName ) );
  if ( !projectDir.exists () ) {

    if ( projectDir.mkpath ( projectDir.path () ) ) {

      done = true;
      if ( verboseMode ) {

        qDebug () << "Creado directorio de proyecto: " << projectDir.path ();
      }
    } else {

      qDebug () << "Error al crear el directorio de proyecto.";
    }
  } else {

    qDebug () << "El directorio de proyecto ya existe: " << projectDir.path ();
  }
  return done;
}

bool CommandProcessor::createStructDirProject ( QString projectPath, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QStringList dirList = { "commands", "resources" };
    for ( const QString &dir : dirList ) {

      QString newPathDir = projectDir.filePath ( dir );
      if ( projectDir.mkpath ( newPathDir ) ) {

        if ( verboseMode ) {

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

bool CommandProcessor::createProjectFile ( QString projectPath, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {



  } else {

    qDebug () << "El directorio de proyecto no existe o no se encuentra: " << projectDir.path ();
  }
  return done;
}
