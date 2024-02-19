#ifndef USERCONFIG_H
#define USERCONFIG_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppSettings.h"
#include "appsystem/ConfigAbs.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT UserConfig : public ConfigAbs {

          public :
            UserConfig ( const QString userConfigFormat );
        };
      }
    }
  }

#endif // USERCONFIG_H
