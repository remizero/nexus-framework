#ifndef PATTERNFACET_H
#define PATTERNFACET_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/FacetAbs.h"

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

          class XSD_EXPORT PatternFacet : public FacetAbs {

              Q_OBJECT
              Q_ENUMS ( properties )

            public :
              Q_INVOKABLE PatternFacet ( QString value = "" );
              PatternFacet ( const PatternFacet& );
              ~PatternFacet ();

              enum properties {

                ID = FacetAbs::properties::ID,
                VALUE = FacetAbs::properties::VALUE
              };
              Q_ENUM ( properties )

              Q_INVOKABLE static int indexOfEnum ( QString enumKey );
              Q_INVOKABLE static bool inEmun ( QString enumKey );
              Q_INVOKABLE static QString enumToString ( properties enumValue );
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::PatternFacet )

#endif // PATTERNFACET_H
