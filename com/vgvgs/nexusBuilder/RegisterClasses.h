#ifndef REGISTERCLASSES_H
#define REGISTERCLASSES_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ProjectAbs.h"
#include "projectType/BlankAppProject.h"
#include "projectType/BlankLibraryProject.h"
#include "projectType/ConsoleAppProject.h"
#include "projectType/GuiAppProject.h"
#include "projectType/NexusAppProject.h"
#include "projectType/PluginProject.h"
#include "projectType/ShareLibraryProject.h"
#include "projectType/SimpleGuiAppProject.h"
#include "projectType/StaticLibraryProject.h"

// Librerías Externas
// External Libraries
#include "Core_global.h"
#include "Patternify_global.h"
#include "creational/Singleton.h"
#include "reflectionsystem/RegisterClassInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT RegisterClasses : public NSLIB_CORE::RegisterClassInterface, public NSLIB_PATTERNIFY::Singleton<RegisterClasses> {

            Q_INTERFACES ( NSLIB_CORE::RegisterClassInterface )

          public:
            ~RegisterClasses () override {}
            void addTypeClass () override;

          private :
            RegisterClasses ();
            friend class NSLIB_PATTERNIFY::Singleton<RegisterClasses>;
        };
      }
    }
  }
}

#endif // REGISTERCLASSES_H
