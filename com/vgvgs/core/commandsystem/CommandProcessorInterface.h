#ifndef COMMANDPROCESSORINTERFACE_H
#define COMMANDPROCESSORINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "CommandInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineParser>
#include <QDebug>
#include <QMap>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT CommandProcessorInterface {

        public :
          virtual ~CommandProcessorInterface () {}
          virtual void processCommands ( QCommandLineParser &parser, QMap<QString, CommandInterface *> commandMap ) = 0;
      };
    }
  }
}

#endif // COMMANDPROCESSORINTERFACE_H
