#ifndef CONFIGABS_H
#define CONFIGABS_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QSettings>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

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
