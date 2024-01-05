#ifndef ATTRIBUTEBUILDER_H
#define ATTRIBUTEBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "ParamBuilder.h"

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

        class BUILDER_EXPORT AttributeBuilder : public ParamBuilder {

          public :
            AttributeBuilder ();

            QString build ();

            const QString &getAccessibility () const;
            void setAccessibility ( const QString &newAccessibility );

          private :
            QString accessibility;
        };
      }
    }
  }
}

#endif // ATTRIBUTEBUILDER_H
