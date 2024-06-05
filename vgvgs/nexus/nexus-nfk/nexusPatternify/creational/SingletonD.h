#ifndef SINGLETOND_H
#define SINGLETOND_H

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
      class PATTERNIFY_EXPORT SingletonD {

          Q_DISABLE_COPY ( SingletonD )

        public :
          SingletonD () {

            assert ( !instance );
            #if defined ( _MSC_VER ) && _MSC_VER < 1200
              int offset = ( int ) ( T* ) 1 - ( int )( SingletonD <T>* ) ( T* ) 1;
              instance = ( T* ) ( ( int ) this + offset );
            #else
              instance = static_cast< T* > ( this );
            #endif
          }

          virtual ~SingletonD () {

            assert ( instance );
            delete instance;
            instance = nullptr;
          }

          static T &getSingleton () {

            assert ( instance );
            return ( *instance );
          }

          static T *getSingletonPtr () {

            return instance;
          }

        protected :
               static T *instance;
          static QMutex *mutex;

        private :
          SingletonD ( const SingletonD<T> & );
      };
      template <typename T>
      QMutex *SingletonD <T>::mutex;
      template <typename T>
      T *SingletonD <T>::instance = nullptr;
    }
  }
}

#endif // SINGLETOND_H
