#include "CommandProcessor.h"


CommandProcessor::CommandProcessor () {}

void CommandProcessor::processCommands ( QCommandLineParser &parser, QMap<QString, NSLIB_CORE::CommandInterface *> commandMap ) {

  parser.addPositionalArgument ( "projectName", QCoreApplication::translate ( "main", "Project Name." ) );
  parser.addPositionalArgument ( "destination", QCoreApplication::translate ( "main", "Destination directory." ) );
  const QStringList optionList = parser.optionNames ();
  QString projectType;
  bool verboseMode = false;

  for ( const QString &option : optionList ) {

    if ( parser.isSet ( option ) ) {

      if ( ( option.compare ( "t" ) == 0 ) || ( option.compare ( "type" ) == 0 ) ) {

        projectType = parser.value ( option );
        if ( projectType.isEmpty () ) {

          qDebug () << "Se debe suministrar un tipo de aplicación: \"gui\" o \"console\".";
          return;
        }
      } else if ( ( option.compare ( "V" ) == 0 ) || ( option.compare ( "verbose" ) == 0 ) ) {

        verboseMode = true;
        qDebug () << "Verbose mode is enabled...";
        qDebug () << "\n";
      }

      NSLIB_CORE::CommandInterface *command = commandMap.value ( option );
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

    this->createProject ( positionalArguments.value ( 0 ), positionalArguments.value ( 1 ), projectType, verboseMode );

  } else {

    qDebug () << "Falta de argumentos.";
  }
}

void CommandProcessor::createProject ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  // Procesar argumentos y opciones según sea necesario
  qDebug () << "Nombre del proyecto: " << projectName;
  qDebug () << "Ruta del destino: " << projectPath;
  qDebug () << "Tipo de proyecto: " << projectType;

  if ( this->createDirProject ( projectName, projectPath, verboseMode ) ) {

    if ( projectType.compare ( "console" ) == 0 ) {



    } else if ( projectType.compare ( "gui" ) == 0 ) {



    } else if ( projectType.compare ( "plugin" ) == 0 ) {


    }
    if ( this->createStructDirProject ( projectPath + projectName + QDir::separator (), verboseMode ) ) {

      if ( this->createProjectFile ( projectName, projectPath + projectName + QDir::separator (), verboseMode ) ) {

        if ( this->createResourcesFile ( projectName, projectPath + projectName + QDir::separator (), verboseMode ) ) {

        }
      }
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

bool CommandProcessor::createProjectFile ( QString projectName, QString projectPath, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    // TODO Como copiar el resto de archivos.
    // TODO Revisar los archivos a copiar y ajustar el código y colocar la macro de notImplement() donde corresponda.
    QStringList resourceList = {
      "projectNameIdentifier.pro",
      "export.def",
      "resources.qrc",
      "main.cpp",
      "CommandProcessor.h", "CommandProcessor.cpp",
      "MainWindow.h", "MainWindow.cpp", "MainWindow.ui",
      "RegisterClasses.h", "RegisterClasses.cpp" };

    for ( const QString &resource : resourceList ) {

      QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( ":/appprojects/resources/application/" + resource );
      if ( ioDeviceFile ) {

        QTextStream in ( ioDeviceFile );
        QString fileContent = in.readAll ();
        ioDeviceFile->close ();
        fileContent.replace ( "projectNameIdentifier", projectName );

        QString fileName = resource;
        fileName.replace ( "projectNameIdentifier", projectName );
        QString destinationPath = projectPath + fileName;
        QFile *newIoDeviceFile = NSLIB_UTILS::Files::load ( destinationPath, QIODevice::WriteOnly | QIODevice::Text );
        if ( newIoDeviceFile ) {

          QTextStream out ( &newIoDeviceFile );
          out << fileContent;
          newIoDeviceFile->close ();
          done = true;
          if ( verboseMode ) {

            qDebug () << "Copiando archivo en directorio de proyecto: " << destinationPath;
          }
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

bool CommandProcessor::createCommandsFile ( QString projectName, QString projectPath, bool verboseMode ) {

  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QStringList resourceList = { "cmdNameIdentifier.h", "cmdNameIdentifier.cpp" };

    for ( const QString &resource : resourceList ) {

      QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( ":/appprojects/resources/application/commands/" + resource );
      if ( ioDeviceFile ) {

        QTextStream in ( ioDeviceFile );
        QString fileContent = in.readAll ();
        ioDeviceFile->close ();
        fileContent.replace ( "projectNameIdentifier", projectName );

        QString fileName = resource;
        fileName.replace ( "projectNameIdentifier", projectName );
        QString destinationPath = projectPath + "commands/" + resource;
        QFile *newIoDeviceFile = NSLIB_UTILS::Files::load ( destinationPath, QIODevice::WriteOnly | QIODevice::Text );
        if ( newIoDeviceFile ) {

          QTextStream out ( &newIoDeviceFile );
          out << fileContent;
          newIoDeviceFile->close ();
          done = true;
          if ( verboseMode ) {

            qDebug () << "Copiando archivo en directorio de proyecto: " << destinationPath;
          }
        } else {

          qDebug () << "No se pudo crear el archivo de recurso de proyecto.";
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

bool CommandProcessor::createResourcesFile ( QString projectName, QString projectPath, bool verboseMode ) {

  // TODO Pasar el valor del typeProject para sustituirlo dentro del archivo config.xml
  bool done = false;
  QDir projectDir ( projectPath );
  if ( projectDir.exists () ) {

    QStringList resourceList = { "config.xml" };

    for ( const QString &resource : resourceList ) {

      QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( ":/appprojects/resources/application/resources/" + resource );
      if ( ioDeviceFile ) {

        QTextStream in ( ioDeviceFile );
        QString fileContent = in.readAll ();
        ioDeviceFile->close ();
        fileContent.replace ( "projectNameIdentifier", projectName );

        QString destinationPath = projectPath + "resources/" + resource;
        QFile *newIoDeviceFile = NSLIB_UTILS::Files::load ( destinationPath, QIODevice::WriteOnly | QIODevice::Text );
        if ( newIoDeviceFile ) {

          QTextStream out ( &newIoDeviceFile );
          out << fileContent;
          newIoDeviceFile->close ();
          done = true;
          if ( verboseMode ) {

            qDebug () << "Copiando archivo en directorio de proyecto: " << destinationPath;
          }
        } else {

          qDebug () << "No se pudo crear el archivo de recurso de proyecto.";
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
