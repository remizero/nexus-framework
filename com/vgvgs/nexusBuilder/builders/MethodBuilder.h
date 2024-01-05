#ifndef METHODBUILDER_H
#define METHODBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "FunctionBuilder.h"

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

            QString build ();

            const QString &getAccessibility () const;
            bool getImplementedIn () const;
            void setAccessibility ( const QString &newAccessibility );
            void setImplementedIn ( bool newImplementedIn );

          private :
            QString accessibility;
            // TODO Crear un enumerado con los valores "Implementation y Header".
            bool implementedIn;
        };
      }
    }
  }
}

#endif // METHODBUILDER_H
