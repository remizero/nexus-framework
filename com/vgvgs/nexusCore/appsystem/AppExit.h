#ifndef APPEXIT_H
#define APPEXIT_H

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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
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

        class CORE_EXPORT AppExit : public QObject, public NSLIB_PATTERNIFY::Singleton<AppExit> {

          public :
            void initialize ( AppConfig *appConfig, UserConfig *userConfig );
            void saveSettings ();
            void saveState ( QMainWindow *parent );

          private :
                  bool initialized;
             AppConfig *appConfig = nullptr;
            UserConfig *userConfig = nullptr;
            AppExit ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<AppExit>;
        };
      }
    }
  }
}

#endif // APPEXIT_H
