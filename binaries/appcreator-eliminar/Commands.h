#ifndef COMMANDS_H
#define COMMANDS_H

// Librerías Internas
// Internal Libraries
#include "commands/VerboseCmd.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core_global.h"
#include "commandsystem/RegisterCommandInterface.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries

class Commands: public NAMESPACE_LIBRARY_CORE::RegisterCommandInterface, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Commands> {

    Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::RegisterCommandInterface )

  public:
    ~Commands () override {}
    void addTypeCommand () override;

  private :
    Commands ();
    friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Commands>;
};

#endif // COMMANDS_H
