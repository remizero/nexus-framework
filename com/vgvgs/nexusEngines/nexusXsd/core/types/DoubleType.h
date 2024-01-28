#ifndef DOUBLETYPE_H
#define DOUBLETYPE_H

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


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT DoubleType : public TypeAbs {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              DoubleType ();
              DoubleType ( const DoubleType& );
              ~DoubleType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
                MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
                MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
                MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
                PATTERN = FacetAbs::facets::PATTERN
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::DoubleType )

#endif // DOUBLETYPE_H
