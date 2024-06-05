#ifndef SINGLETONS_H
#define SINGLETONS_H

// Librerías Internas
// Internal Libraries
#include "Patternify_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

// Librerías C++
// C++ Libraries
#include <iostream>


namespace NS_VGVGS {

  namespace NS_NEXUS {

    namespace NS_PATTERNIFY {

      template <typename T>
      class PATTERNIFY_EXPORT SingletonS {

          Q_DISABLE_COPY ( SingletonS )

        public :
          virtual ~SingletonS () {

            assert ( instance );
            delete instance;
            instance = nullptr;
          }

          static T &getSingleton () {

            assert ( instance );
            return ( *instance );
          }

        protected :
               static T *instance;
          static QMutex *mutex;

        private :
          SingletonS () {}
          SingletonS ( const SingletonS<T> & );
      };
      template <typename T>
      QMutex *SingletonS <T>::mutex;
      template <typename T>
      T *SingletonS <T>::instance = nullptr;
    }
  }
}

#endif // SINGLETONS_H
