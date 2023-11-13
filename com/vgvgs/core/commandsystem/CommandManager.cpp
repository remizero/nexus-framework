#include "CommandManager.h"


using namespace NAMESPACE_LIBRARY_CORE;


CommandManager::CommandManager ( QObject *parent ) : QObject ( parent ) {

  this->initialized = false;
}

void CommandManager::initialize ( AppConfig *appConfig ) {

  parser.setApplicationDescription ( appConfig->getSettings ()->value ( "app/applicationdescription" ).toString () );
  parser.addHelpOption ();
  parser.addVersionOption ();
  this->initialized = true;
}

void CommandManager::executeCommand ( QCoreApplication *application, int &argc, char *argv [] ) {

  if ( this->initialized ) {

    parser.process ( *application );
    const QStringList optionList = parser.optionNames ();

    for ( const QString &option : optionList ) {

      if ( parser.isSet ( option ) ) {

        // TODO Como procesar modificadores para tareas de comandos?
        // Almacena los comandos de primer nivel
//        QStringList primaryCommands;
        // Analizar el nombre del comando para determinar el nivel
//        if ( option.contains ( "-" ) ) {

//            // Comando de segundo nivel
//            // Puedes almacenar o procesar de acuerdo a tu lógica específica

//          } else {

//            // Comando de primer nivel
//            primaryCommands << option;
//          }
//        processPrimaryCommands ( primaryCommands );
        CommandInterface *command = commandMap.value ( option );
        if ( command ) {

          Logger::getInstance ()->uninstallMessageHandler ();
          command->execute ();
          Logger::getInstance ()->reinstallMessageHandler ();

        } else {

          qDebug () << "Comando no encontrado para la opción:" << option;
        }
      }
    }
  } else {

    qDebug () << "La clase CommandManager no ha sido inicializa correctamente.";
  }
}

void CommandManager::processPrimaryCommands ( const QStringList &commands ) {

  // Lógica para procesar los comandos de primer nivel
  for ( const QString &primaryCommand : commands ) {

    if ( primaryCommand == "tarea_a_realizar" ) {

      qDebug () << "Realizando tarea_a_realizar...";

    } else {

      qDebug () << "Comando de primer nivel no reconocido:" << primaryCommand;
    }
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

          parser.addOption ( command->commandOption () );
          commandMap.insert ( command->name (), command );

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
