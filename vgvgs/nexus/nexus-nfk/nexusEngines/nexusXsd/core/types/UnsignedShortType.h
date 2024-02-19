#ifndef UNSIGNEDSHORTTYPE_H
#define UNSIGNEDSHORTTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "UnsignedIntType.h"

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

          class XSD_EXPORT UnsignedShortType : public UnsignedIntType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              UnsignedShortType ();
              UnsignedShortType ( const UnsignedShortType& );
              ~UnsignedShortType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::UnsignedShortType )

#endif // UNSIGNEDSHORTTYPE_H
