#ifndef APPINIT_H
#define APPINIT_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppConfig.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppSettings.h"
#include "appsystem/UserConfig.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDockWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QVariant>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT AppInit : public QObject, public NSLIB_PATTERNIFY::Singleton<AppInit> {

          public :
            bool checkVersion ();
            AppConfig *getAppConfig () const;
            UserConfig *getUserConfig () const;
            void initialize ( AppConfig *appConfig, UserConfig *userConfig );
            bool restoreDockWidget ( QMainWindow *parent, QDockWidget *dockWidget );
            bool restoreGeometry ( QMainWindow *parent );
            bool restoreState ( QMainWindow *parent );

          private :
                  bool initialized;
             AppConfig *appConfig = nullptr;
            UserConfig *userConfig = nullptr;
            AppInit ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<AppInit>;
        };
      }
    }
  }
}

#endif // APPINIT_H
