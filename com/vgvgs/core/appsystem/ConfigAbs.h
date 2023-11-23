#ifndef CONFIGABS_H
#define CONFIGABS_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QSettings>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_CORE {

      class CORE_EXPORT ConfigAbs {

        public :
          ConfigAbs ();

          QSettings *getSettings () const;

        protected :
          QSettings::Format configFormat;
                  QSettings *settings;
      };
    }
  }
}

#endif // CONFIGABS_H
