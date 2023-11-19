#ifndef REGISTERCLASSES_H
#define REGISTERCLASSES_H

// Librerías Internas
// Internal Libraries
#include "commands/TypeCmd.h"
#include "CommandProcessor.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core_global.h"
#include "creational/Singleton.h"
#include "reflectionsystem/RegisterClassInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


class RegisterClasses : public NAMESPACE_LIBRARY_CORE::RegisterClassInterface, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<RegisterClasses> {

    Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::RegisterClassInterface )

  public:
    ~RegisterClasses () override {}
    void addTypeClass () override;

  private :
    RegisterClasses ();
    friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<RegisterClasses>;
};

#endif // REGISTERCLASSES_H
