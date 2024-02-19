#ifndef REGISTERCOMMANDINTERFACE_H
#define REGISTERCOMMANDINTERFACE_H

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

        class CORE_EXPORT RegisterCommandInterface {

          public :
            virtual ~RegisterCommandInterface () {}
            virtual void addTypeCommand () = 0;
        };
      }
    }
  }

#endif // REGISTERCOMMANDINTERFACE_H
