#ifndef METHODBUILDER_H
#define METHODBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "FunctionBuilder.h"
#include "NexusBuilder.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT MethodBuilder : public FunctionBuilder {

          public :
            MethodBuilder ();

            QString build ( NexusBuilder::FileClasses fileClass, NexusBuilder::TypeBuild typeBuild, QString memberScope );

            NexusBuilder::Accessibility getAccessibility ();
            bool getImplementedIn () const;
            void setAccessibility ( NexusBuilder::Accessibility newAccessibility );
            void setImplementedIn ( bool newImplementedIn );

          private :
            NexusBuilder::Accessibility accessibility;
            bool implementedIn;
        };
      }
    }
  }
}

#endif // METHODBUILDER_H
