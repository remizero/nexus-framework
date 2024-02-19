#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

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

          class XSD_EXPORT EntityType : public NCNameType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              EntityType ();
              EntityType ( const EntityType& );
              ~EntityType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::EntityType )

#endif // ENTITYTYPE_H
