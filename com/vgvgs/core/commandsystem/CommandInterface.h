#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

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
