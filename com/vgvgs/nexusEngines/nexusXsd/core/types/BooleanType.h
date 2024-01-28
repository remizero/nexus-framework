#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/TypeAbs.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "Enumeration.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT BooleanType : public TypeAbs {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              BooleanType ();
              BooleanType ( const BooleanType& );
              ~BooleanType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                PATTERN = FacetAbs::facets::PATTERN
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::BooleanType )

#endif // BOOLEANTYPE_H
