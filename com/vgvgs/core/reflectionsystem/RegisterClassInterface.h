#ifndef REGISTERCLASSINTERFACE_H
#define REGISTERCLASSINTERFACE_H

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

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

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
