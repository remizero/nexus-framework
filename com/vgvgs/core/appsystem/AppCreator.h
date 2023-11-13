#ifndef APPCREATOR_H
#define APPCREATOR_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppCreator {

        public:
          AppCreator ( const QString &path = QString ( "" ) );

          void createProject ();
          void createDirProject ();
          void createMainCpp ();
          void createResources ();
//          void create ();
//          void create ();
//          void create ();
//          void create ();
//          void create ();

        private :
          const QString path;
        };
      }
    }
  }

#endif // APPCREATOR_H
