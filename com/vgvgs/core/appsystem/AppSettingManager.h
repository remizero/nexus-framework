#ifndef APPSETTINGMANAGER_H
#define APPSETTINGMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppSettings.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppSettingManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppSettingManager> {

        public :
          void initialize ();

          const QSettings::Format &getUserConfigFormat () const;
          void setUserConfigFormat ( const QSettings::Format &newUserConfigFormat );

        private :
          QSettings::Format appConfigFormat;
          QSettings::Format userConfigFormat;
          AppSettingManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppSettingManager>;
      };
    }
  }
}

#endif // APPSETTINGMANAGER_H
