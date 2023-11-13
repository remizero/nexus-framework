#ifndef APPMANAGER_H
#define APPMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/App.h"
#include "appsystem/AppConfig.h"
#include "appsystem/AppExit.h"
#include "appsystem/AppInit.h"
#include "appsystem/AppPaths.h"
#include "appsystem/UserConfig.h"
#include "commandsystem/CommandManager.h"
#include "loggersystem/Logger.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QMainWindow>
#include <QObject>
#include <QTimer>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppManager> {

          Q_OBJECT

        public :
          void create ( int &argc, char *argv [] );
          int execute ( int &argc, char *argv [], QMainWindow *mainWindow = nullptr );
          AppConfig *getAppConfig () const;
          UserConfig *getUserConfig () const;
          void initialize ();
          bool isGuiApp ();

        private :
                      bool initialized;
                 AppConfig *appConfig = nullptr;
                UserConfig *userConfig = nullptr;
          QCoreApplication *application;
          void cleanArg ( int &argc, char *argv [] );
          void setAppInfo ( QCoreApplication *application );
          AppManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppManager>;
      };
    }
  }
}

#endif // APPMANAGER_H
