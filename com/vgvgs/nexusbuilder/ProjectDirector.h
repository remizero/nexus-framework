#ifndef PROJECTDIRECTOR_H
#define PROJECTDIRECTOR_H

// Librerías Internas
// Internal Libraries
#include "nexusbuilder_global.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUSBUILDER {

      class NEXUSBUILDER_EXPORT ProjectDirector {

        public :
          ProjectDirector ();

          bool create ( ProjectInterface *project );

      };
    }
  }
}

#endif // PROJECTDIRECTOR_H
