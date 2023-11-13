#ifndef REGISTERCOMMAND_H
#define REGISTERCOMMAND_H

// Librerías Internas
// Internal Libraries
#include "commands/InfoCmd.h"

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

class RegisterCommand: public NAMESPACE_LIBRARY_CORE::RegisterCommandInterface, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<RegisterCommand> {

    Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::RegisterCommandInterface )

  public:
    ~RegisterCommand () override {}
    void addTypeCommand () override;

  private :
    RegisterCommand ();
    friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<RegisterCommand>;
  };

#endif // REGISTERCOMMAND_H
