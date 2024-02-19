#ifndef NONPOSITIVEINTEGERTYPE_H
#define NONPOSITIVEINTEGERTYPE_H

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT NonPositiveIntegerType : public IntegerType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              NonPositiveIntegerType ();
              NonPositiveIntegerType ( const NonPositiveIntegerType& );
              ~NonPositiveIntegerType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::NonPositiveIntegerType )

#endif // NONPOSITIVEINTEGERTYPE_H
