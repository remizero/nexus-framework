#ifndef APPSETTINGMANAGER_H
#define APPSETTINGMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppSettings.h"

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT AppSettingManager : public QObject, public NSLIB_PATTERNIFY::Singleton<AppSettingManager> {

          public :
            void initialize ();
            const QSettings::Format &getUserConfigFormat () const;
            void setUserConfigFormat ( const QSettings::Format &newUserConfigFormat );

          private :
            QSettings::Format appConfigFormat;
            QSettings::Format userConfigFormat;
            AppSettingManager ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<AppSettingManager>;
        };
      }
    }
  }

#endif // APPSETTINGMANAGER_H
