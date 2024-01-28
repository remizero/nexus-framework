#ifndef UNSIGNEDLONGTYPE_H
#define UNSIGNEDLONGTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "NonNegativeIntegerType.h"

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

          class XSD_EXPORT UnsignedLongType : public NonNegativeIntegerType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              UnsignedLongType ();
              UnsignedLongType ( const UnsignedLongType& );
              ~UnsignedLongType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
                MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
                TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::UnsignedLongType )

#endif // UNSIGNEDLONGTYPE_H
