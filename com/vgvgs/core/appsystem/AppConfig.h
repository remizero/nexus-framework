#ifndef APPCONFIG_H
#define APPCONFIG_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppSettings.h"
#include "appsystem/ConfigAbs.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_CORE {

      class CORE_EXPORT AppConfig : public ConfigAbs {

        public :
          AppConfig ();
      };
    }
  }
}

#endif // APPCONFIG_H
