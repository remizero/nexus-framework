#ifndef MCAREGISTERCLASSES_H
#define MCAREGISTERCLASSES_H

// Librerías Internas
// Internal Libraries
#include "commands/InfoCmd.h"
#include "commands/TypeCmd.h"
#include "CommandProcessor.h"

// Librerías Externas
// External Libraries
#include "Core_global.h"
#include "creational/Singleton.h"
#include "reflectionsystem/RegisterClassInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


class RegisterClasses : public NSLIB_CORE::RegisterClassInterface, public NSLIB_PATTERNIFY::Singleton<RegisterClasses> {

    Q_INTERFACES ( NSLIB_CORE::RegisterClassInterface )

  public:
    ~RegisterClasses () override {}
    void addTypeClass () override;

  private :
    RegisterClasses ();
    friend class NSLIB_PATTERNIFY::Singleton<RegisterClasses>;
};

#endif // MCAREGISTERCLASSES_H
