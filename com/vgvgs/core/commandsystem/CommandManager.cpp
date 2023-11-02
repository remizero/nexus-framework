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

    // Parsea los argumentos de la línea de comandos.
    parser.process ( *application );

    // Verifica los argumentos comportamentales.
    if ( parser.isSet ( "debug" ) ) {
      // Activa el modo de depuración.
    }

    if ( parser.isSet ( "version" ) ) {
      // Muestra la versión de la aplicación.
    }
  } else {

    qDebug () << "La clase CommandManager no ha sido inicializa correctamente.";
  }


  /**
   * FORMA 2
   */
//  QCommandLineParser parser;
//  parser.addOption(QCommandLineOption("input", "Archivo de entrada.", "archivo"));
//  parser.addPositionalArgument("comando", "Comando a ejecutar (por ejemplo, 'mi_comando').");
//  parser.process(app);

//  const QString inputFile = parser.value("input");
//  const QStringList positionalArguments = parser.positionalArguments();

//  if (positionalArguments.isEmpty()) {
//      qDebug() << "Debe proporcionar un comando.";
//      return 1;
//  }

//  const QString comando = positionalArguments.at(0);

//  if (comando == "mi_comando") {
//      // Ejecuta tu comando personalizado aquí.
//      qDebug() << "Ejecutando 'mi_comando'...";
//  } else {
//      qDebug() << "Comando desconocido: " << comando;
//      return 1;
//  }
}

void CommandManager::setCustomCommands ( AppConfig *appConfig ) {

  if ( this->initialized ) {

    int size = appConfig->getSettings ()->beginReadArray ( "logins" );
    for ( int i = 0; i < size; ++i ) {

      appConfig->getSettings ()->setArrayIndex ( i );
      parser.addOption ( QCommandLineOption (
                           appConfig->getSettings ()->value ( "command/name" ).toString (),
                           appConfig->getSettings ()->value ( "command/description" ).toString () ) );
    }
    appConfig->getSettings ()->endArray ();

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente.";
  }
}
