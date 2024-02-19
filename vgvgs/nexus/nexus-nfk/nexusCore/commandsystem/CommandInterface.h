#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineOption>
#include <QDebug>
#include <QString>

// Librerías C++
// C++ Libraries
#include <iostream>


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT CommandInterface {

          public :
            virtual ~CommandInterface () {}
            virtual QCommandLineOption commandOption () const = 0;
            virtual QString description () const = 0;
            virtual void execute () = 0;
            virtual QString name () const = 0;
        };
      }
    }
  }

#endif // COMMANDINTERFACE_H
