#ifndef PLUGINABS_H
#define PLUGINABS_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "PluginInfo.h"
#include "PluginActionInfo.h"
#include "PluginActionLocationInfo.h"
#include "PluginDependenciesInfo.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT PluginAbs {

          public :
            void static initializeMetadata ( PluginInfo *pluginInfo, QJsonObject object );
        };
      }
    }
  }

#endif // PLUGINABS_H
