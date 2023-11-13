#ifndef REGISTERCOMMANDINTERFACE_H
#define REGISTERCOMMANDINTERFACE_H

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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT RegisterCommandInterface {

        public :
          virtual ~RegisterCommandInterface () {}
          virtual void addTypeCommand () = 0;
      };
    }
  }
}

#endif // REGISTERCOMMANDINTERFACE_H
