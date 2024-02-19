#ifndef PROJECTDIRECTOR_H
#define PROJECTDIRECTOR_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectInterface.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ProjectDirector {

          public :
            static bool create ( ProjectInterface *project );
        };
      }
    }
  }

#endif // PROJECTDIRECTOR_H
