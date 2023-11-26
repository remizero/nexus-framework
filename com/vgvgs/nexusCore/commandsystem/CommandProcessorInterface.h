#ifndef COMMANDPROCESSORINTERFACE_H
#define COMMANDPROCESSORINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "CommandInterface.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineParser>
#include <QDebug>
#include <QMap>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT CommandProcessorInterface {

          public :
            virtual ~CommandProcessorInterface () {}
            virtual void processCommands ( QCommandLineParser &parser, QMap<QString, CommandInterface *> commandMap ) = 0;
        };
      }
    }
  }
}

#endif // COMMANDPROCESSORINTERFACE_H
