#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppConfig.h"
#include "commandsystem/CommandInterface.h"
#include "commandsystem/CommandProcessorInterface.h"
#include "commandsystem/VerboseCmd.h"
#include "loggersystem/Logger.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include <QMap>
#include <QObject>
#include <QStringList>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT CommandManager : public QObject, public NSLIB_PATTERNIFY::Singleton<CommandManager> {

            Q_OBJECT

          public :
            void executeCommand ( QCoreApplication *application );
            void initialize ( AppConfig *appConfig );
            void setCustomCommands ( AppConfig *appConfig );

          private :
                                         bool initialized;
            QMap<QString, CommandInterface *> commandMap;
            QCommandLineParser parser;
            void setupBasicCommands ();
            void showAppInfo ( QCoreApplication *application );
            CommandManager ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<CommandManager>;
        };
      }
    }
  }

#endif // COMMANDMANAGER_H
