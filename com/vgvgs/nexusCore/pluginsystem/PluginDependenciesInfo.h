#ifndef PLUGINDEPENDENCIESINFO_H
#define PLUGINDEPENDENCIESINFO_H

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
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT PluginDependenciesInfo {

          public :

            const QString &getName () const;
            void setName ( const QString &newName );

            const QString &getVersion () const;
            void setVersion ( const QString &newVersion );

          private :
            QString name;
            QString version;

        };
      }
    }
  }
}

#endif // PLUGINDEPENDENCIESINFO_H
