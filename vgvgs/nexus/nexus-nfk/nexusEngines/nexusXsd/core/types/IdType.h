#ifndef IDTYPE_H
#define IDTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "NCNameType.h"

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

          class XSD_EXPORT IdType : public NCNameType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              IdType ();
              IdType ( const IdType& );
              ~IdType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::IdType )

#endif // IDTYPE_H
