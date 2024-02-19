#ifndef UNSIGNEDBYTETYPE_H
#define UNSIGNEDBYTETYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "UnsignedShortType.h"

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

          class XSD_EXPORT UnsignedByteType : public UnsignedShortType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              UnsignedByteType ();
              UnsignedByteType ( const UnsignedByteType& );
              ~UnsignedByteType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::UnsignedByteType )

#endif // UNSIGNEDBYTETYPE_H
