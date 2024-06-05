#ifndef SINGLETONP_H
#define SINGLETONP_H

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
      class PATTERNIFY_EXPORT SingletonP {

          Q_DISABLE_COPY ( SingletonP )

        public :
          virtual ~SingletonP () {

            assert ( instance );
            delete instance;
            instance = nullptr;
          }

          static T *getSingletonPtr () {

            return instance;
          }

        protected :
               static T *instance;
          static QMutex *mutex;

        private :
          SingletonP () {}
          SingletonP ( const SingletonP<T> & );
      };
      template <typename T>
      QMutex *SingletonP <T>::mutex;
      template <typename T>
      T *SingletonP <T>::instance = nullptr;
    }
  }
}

#endif // SINGLETONP_H
