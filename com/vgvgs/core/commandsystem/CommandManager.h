#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppConfig.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT CommandManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<CommandManager> {

          Q_OBJECT

        public :
          void executeCommand ( QCoreApplication *application, int &argc, char *argv [] );
          void initialize ( AppConfig *appConfig );
          void setCustomCommands ( AppConfig *appConfig );

        private :
                        bool initialized;
          QCommandLineParser parser;
          CommandManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<CommandManager>;
      };
    }
  }
}

#endif // COMMANDMANAGER_H
