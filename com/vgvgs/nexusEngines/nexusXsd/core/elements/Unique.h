#ifndef UNIQUE_H
#define UNIQUE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "core/ElementAbs.h"
#include "core/PropertyAbs.h"


// Librerías Externas
// External Libraries
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

          class XSD_EXPORT Unique : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE Unique ();
              Unique ( const Unique& );
              ~Unique ();

              enum content {

                ANNOTATION = ElementAbs::elements::ANNOTATION,
                FIELD = ElementAbs::elements::FIELD,
                SELECTOR = ElementAbs::elements::SELECTOR
              };
              Q_ENUM ( content )

              enum properties {

                ID = PropertyAbs::properties::ID,
                NAME = PropertyAbs::properties::NAME,
                REF = PropertyAbs::properties::REF
              };
              Q_ENUM ( properties )

              Q_INVOKABLE static int indexOfContentEnum ( QString enumKey );
              Q_INVOKABLE static bool inContentEmun ( QString enumKey );
              Q_INVOKABLE static QString contentEnumToString ( content enumValue );
              Q_INVOKABLE static int indexOfPropertiesEnum ( QString enumKey );
              Q_INVOKABLE static bool inPropertiesEmun ( QString enumKey );
              Q_INVOKABLE static QString propertiesEnumToString ( properties enumValue );
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::Unique )

#endif // UNIQUE_H
