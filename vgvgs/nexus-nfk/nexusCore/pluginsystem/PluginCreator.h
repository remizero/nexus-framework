#ifndef PLUGINCREATOR_H
#define PLUGINCREATOR_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

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

        class CORE_EXPORT PluginCreator : public NSLIB_PATTERNIFY::Singleton<PluginCreator> {

          public :

          private :
            PluginCreator ();
            friend class NSLIB_PATTERNIFY::Singleton<PluginCreator>;
        };
      }
    }
  }

#endif // PLUGINCREATOR_H
