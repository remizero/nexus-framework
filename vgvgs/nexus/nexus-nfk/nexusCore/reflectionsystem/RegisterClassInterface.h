#ifndef REGISTERCLASSINTERFACE_H
#define REGISTERCLASSINTERFACE_H

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

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT RegisterClassInterface {

          public :
            virtual ~RegisterClassInterface () {}
            virtual void addTypeClass () = 0;
        };
      }
    }
  }

#endif // REGISTERCLASSINTERFACE_H
