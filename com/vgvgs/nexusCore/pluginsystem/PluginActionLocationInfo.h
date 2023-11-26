#ifndef PLUGINACTIONLOCATIONINFO_H
#define PLUGINACTIONLOCATIONINFO_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QFont>
#include <QIcon>
#include <QKeySequence>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT PluginActionLocationInfo {

          public :

            const QString &getContextual () const;
            void setContextual ( const QString &newContextual );
            const QString &getMenu () const;
            void setMenu ( const QString &newMenu );
            const QString &getToolbar () const;
            void setToolbar ( const QString &newToolbar );

          private :
            QString contextual;
            QString menu;
            QString toolbar;
        };
      }
    }
  }
}

#endif // PLUGINACTIONLOCATIONINFO_H
