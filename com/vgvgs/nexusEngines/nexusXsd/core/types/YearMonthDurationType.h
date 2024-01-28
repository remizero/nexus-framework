#ifndef YEARMONTHDURATIONTYPE_H
#define YEARMONTHDURATIONTYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "DurationType.h"

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

          class XSD_EXPORT YearMonthDurationType : public DurationType {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              YearMonthDurationType ();
              YearMonthDurationType ( const YearMonthDurationType& );
              ~YearMonthDurationType ();

              enum facets {

                ASSERTIONS = FacetAbs::facets::ASSERTIONS,
                ENUMERATION = FacetAbs::facets::ENUMERATION,
                MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
                MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
                MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
                MININCLUSIVE = FacetAbs::facets::MININCLUSIVE
              };
              Q_ENUM ( facets )
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::YearMonthDurationType )

#endif // YEARMONTHDURATIONTYPE_H
