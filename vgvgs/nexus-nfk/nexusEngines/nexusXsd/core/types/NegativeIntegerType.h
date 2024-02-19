#ifndef NEGATIVEINTEGERTYPE_H
#define NEGATIVEINTEGERTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "NonPositiveIntegerType.h"

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT NegativeIntegerType : public NonPositiveIntegerType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              NegativeIntegerType ();
              NegativeIntegerType ( const NegativeIntegerType& );
              ~NegativeIntegerType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
                MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
                MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
                TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::NegativeIntegerType )

#endif // NEGATIVEINTEGERTYPE_H
