#ifndef BASE64BINARYTYPE_H
#define BASE64BINARYTYPE_H

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT Base64BinaryType : public TypeAbs {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              Base64BinaryType ();
              Base64BinaryType ( const Base64BinaryType& );
              ~Base64BinaryType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                LENGTH = FacetAbs::facets::LENGTH,
                MAXLENGTH = FacetAbs::facets::MAXLENGTH,
                MINLENGTH = FacetAbs::facets::MINLENGTH,
                PATTERN = FacetAbs::facets::PATTERN
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::Base64BinaryType )

#endif // BASE64BINARYTYPE_H
