#ifndef NONNEGATIVEINTEGERTYPE_H
#define NONNEGATIVEINTEGERTYPE_H

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

          class XSD_EXPORT NonNegativeIntegerType : public IntegerType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              NonNegativeIntegerType ();
              NonNegativeIntegerType ( const NonNegativeIntegerType& );
              ~NonNegativeIntegerType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
                MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
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
Q_DECLARE_METATYPE ( NSLIB_XSD::NonNegativeIntegerType )

#endif // NONNEGATIVEINTEGERTYPE_H
