#ifndef ACTIONINTERFACE_H
#define ACTIONINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT ActionInterface {

          public slots :
            virtual void execAct () = 0;
        };
      }
    }
  }
}

Q_DECLARE_INTERFACE ( NSLIB_CORE::ActionInterface, "com.vgvgs.core.ActionInterface" )

#endif // ACTIONINTERFACE_H
