#ifndef NOTATIONTYPE_H
#define NOTATIONTYPE_H

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

          class XSD_EXPORT NotationType : public TypeAbs {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              NotationType ();
              NotationType ( const NotationType& );
              ~NotationType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::NotationType )

#endif // NOTATIONTYPE_H
