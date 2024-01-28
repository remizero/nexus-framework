#ifndef LONGTYPE_H
#define LONGTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "IntegerType.h"

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

          class XSD_EXPORT LongType : public IntegerType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              LongType ();
              LongType ( const LongType& );
              ~LongType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::LongType )

#endif // LONGTYPE_H
