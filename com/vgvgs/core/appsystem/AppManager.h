#ifndef APPMANAGER_H
#define APPMANAGER_H

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
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppManager> {

          Q_OBJECT

        public :

        private :
          AppManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppManager>;
      };
    }
  }
}

#endif // APPMANAGER_H
