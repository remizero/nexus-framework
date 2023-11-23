#include "CommandManager.h"


using namespace NSLIB_CORE;


CommandManager::CommandManager ( QObject *parent ) : QObject ( parent ) {

  qRegisterMetaType<VerboseCmd>( "VerboseCmd" );
  this->initialized = false;
}

void CommandManager::initialize ( AppConfig *appConfig ) {

  parser.setApplicationDescription ( appConfig->getSettings ()->value ( "app/applicationdescription" ).toString () );
  parser.addHelpOption ();
  parser.addVersionOption ();
  this->initialized = true;
  this->setupBasicCommands ();
}

void CommandManager::executeCommand ( QCoreApplication *application ) {

  if ( this->initialized ) {

    parser.process ( *application );
    QMetaType typeId = QMetaType::fromName ( "CommandProcessor" );
    if ( typeId.isValid () ) {

      CommandProcessorInterface *commandProcessor = static_cast<CommandProcessorInterface *> ( typeId.create () );
      if ( commandProcessor ) {

        Logger::getInstance ()->uninstallMessageHandler ();
        this->showAppInfo ( application );
        commandProcessor->processCommands ( parser, commandMap );
        Logger::getInstance ()->reinstallMessageHandler ();

      } else {

        qDebug () << "Error al crear el procesador de comandos.";
      }
    } else {

      qDebug () << "Nombre de clase desconocida.";
    }
  } else {

    qDebug () << "La clase CommandManager no ha sido inicializa correctamente.";
  }
}

void CommandManager::setCustomCommands ( AppConfig *appConfig ) {

  if ( this->initialized ) {

    appConfig->getSettings ()->beginGroup ( "commands" );
    QStringList commandNames = appConfig->getSettings ()->allKeys ();

    for ( const QString &commandName : commandNames ) {

      QString className = appConfig->getSettings ()->value ( commandName ).toString ();
      QMetaType typeId = QMetaType::fromName ( className.toUtf8 () );
      if ( typeId.isValid () ) {

        CommandInterface *command = static_cast<CommandInterface *> ( typeId.create () );
        if ( command ) {

          QCommandLineOption option = command->commandOption ();
          parser.addOption ( option );
          QStringList optionNames = option.names ();
          for ( const QString &name : optionNames ) {

            commandMap.insert ( name, command );
          }
        } else {

          qDebug () << "Error al crear el comando para" << commandName;
        }
      } else {

        qDebug () << "Nombre de clase desconocido:" << className;
      }
    }
    appConfig->getSettings ()->endGroup ();

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente.";
  }
}

void CommandManager::setupBasicCommands () {

  // TODO crear estos comandos básicos de forma dinámica desde un archivo de configuración interno de esta librería.
  if ( this->initialized ) {

    QMetaType typeId = QMetaType::fromName ( "VerboseCmd" );
    if ( typeId.isValid () ) {

      CommandInterface *command = static_cast<CommandInterface *> ( typeId.create () );
      if ( command ) {

        QCommandLineOption option = command->commandOption ();
        parser.addOption ( option );
        QStringList optionNames = option.names ();
        for ( const QString &name : optionNames ) {

          commandMap.insert ( name, command );
        }
      } else {

        qDebug () << "Error al crear el comando para" << "VerboseCmd";
      }
    } else {

      qDebug () << "Nombre de clase desconocido:" << "VerboseCmd";
    }
  }
}

void CommandManager::showAppInfo ( QCoreApplication *application ) {

  qDebug () << " ";
  qDebug () << "Nombre de la aplicación: " << application->applicationName ();
  qDebug () << "Versión de la aplicación: " << application->applicationVersion ();
  qDebug () << "Nombre del fabricante: " << application->organizationName ();
  qDebug () << "Website  del fabricante: " << application->organizationDomain ();
  qDebug () << " ";
  qDebug () << " ";
}
