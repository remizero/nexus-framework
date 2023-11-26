#ifndef REGISTERCLASSES_H
#define REGISTERCLASSES_H

// Librerías Internas
// Internal Libraries
#include "commands/TypeCmd.h"
#include "CommandProcessor.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
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

#endif // REGISTERCLASSES_H
