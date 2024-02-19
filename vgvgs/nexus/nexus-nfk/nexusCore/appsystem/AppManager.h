#ifndef APPMANAGER_H
#define APPMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/App.h"
#include "appsystem/AppConfig.h"
#include "appsystem/AppExit.h"
#include "appsystem/AppInit.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppUtils.h"
#include "appsystem/UserConfig.h"
#include "commandsystem/CommandManager.h"
#include "loggersystem/Logger.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QTimer>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT AppManager : public QObject, public NSLIB_PATTERNIFY::Singleton<AppManager> {

            Q_OBJECT

          public :
            void create ( int &argc, char *argv [] );
            void createConsoleOnly ( int &argc, char *argv [] );
            void createGuiOnly ( int &argc, char *argv [] );
            int execute ( QMainWindow *mainWindow = nullptr );
            int executeConsoleOnly ();
            int executeGuiOnly ( QMainWindow *mainWindow );
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
            friend class NSLIB_PATTERNIFY::Singleton<AppManager>;
        };
      }
    }
  }

#endif // APPMANAGER_H
