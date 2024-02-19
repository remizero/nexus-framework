#ifndef NMTOKENTYPE_H
#define NMTOKENTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "TokenType.h"

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

          class XSD_EXPORT NMTokenType : public TokenType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              NMTokenType ();
              NMTokenType ( const NMTokenType& );
              ~NMTokenType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                LENGTH = FacetAbs::facets::LENGTH,
                MAXLENGTH = FacetAbs::facets::MAXLENGTH,
                MINLENGTH = FacetAbs::facets::MINLENGTH
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::NMTokenType )

#endif // NMTOKENTYPE_H
