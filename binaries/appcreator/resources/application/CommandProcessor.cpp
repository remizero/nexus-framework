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

      if ( ( option.compare ( "V" ) == 0 ) || ( option.compare ( "verbose" ) == 0 ) ) {

        verboseMode = true;
        qDebug () << "Verbose mode is enabled...";
        qDebug () << "\n";
      } else {

        // TODO A partir de aquí puede comprobar todas las opciones o flags
        //      personalizadas que utiliza la aplicación.
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

    // TODO Aquí puede hacer el llamado a todos los métodos personalizados que
    //      sean requeridos en la aplicación para procesar todos los argumentos
    //      suministrados en la línea de comandos.

  } else {

    qDebug () << "Falta de argumentos.";
  }
}
