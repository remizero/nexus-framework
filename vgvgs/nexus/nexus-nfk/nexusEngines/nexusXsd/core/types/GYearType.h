#ifndef GYEARTYPE_H
#define GYEARTYPE_H

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

          class XSD_EXPORT GYearType : public TypeAbs {

              Q_OBJECT
              Q_ENUMS ( facets )

            public :
              GYearType ();
              GYearType ( const GYearType& );
              ~GYearType ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::GYearType )

#endif // GYEARTYPE_H
