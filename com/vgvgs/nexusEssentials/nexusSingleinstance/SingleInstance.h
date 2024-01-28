#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

// Librerías Internas
// Internal Libraries
#include "Singleinstance_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QObject>
#include <QSharedMemory>
#include <QSystemSemaphore>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_SINGLEINSTANCE {

        class SINGLEINSTANCE_EXPORT SingleInstance {

          public :
            SingleInstance ( const QString &key );
            ~SingleInstance ();

            bool isAnotherRunning ();
            bool tryToRun ();
            void release ();

          private :
            const QString key;
            const QString memLockKey;
            const QString sharedmemKey;
            QSharedMemory sharedMem;
            QSystemSemaphore memLock;

            Q_DISABLE_COPY( SingleInstance )
        };
      }
    }
  }
}

#endif // SINGLEINSTANCE_H
