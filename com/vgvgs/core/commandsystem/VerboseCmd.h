#ifndef VERBOSECMD_H
#define VERBOSECMD_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "commandsystem/CommandInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineOption>
#include <QDebug>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT VerboseCmd : public CommandInterface {

          Q_INTERFACES ( CommandInterface )

        public :
          VerboseCmd ();
          ~VerboseCmd () override {}
          QCommandLineOption commandOption () const override;
          QString description () const override;
          void execute () override;
          QString name () const override;
      };
    }
  }
}

Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_CORE::VerboseCmd )

#endif // VERBOSECMD_H
