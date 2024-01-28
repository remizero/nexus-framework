#ifndef SIMPLETYPE_H
#define SIMPLETYPE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/ElementAbs.h"

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

          class XSD_EXPORT SimpleType : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE SimpleType ();
              SimpleType ( const SimpleType& );
              ~SimpleType ();

              enum content {

                ANNOTATION = ElementAbs::elements::ANNOTATION,
                LIST = ElementAbs::elements::LIST,
                RESTRICTION = ElementAbs::elements::RESTRICTION,
                UNION = ElementAbs::elements::UNION
              };
              Q_ENUM ( content )

              enum properties {

                FINAL = PropertyAbs::properties::FINAL,
                ID = PropertyAbs::properties::ID,
                NAME = PropertyAbs::properties::NAME
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
Q_DECLARE_METATYPE ( NSLIB_XSD::SimpleType )

#endif // SIMPLETYPE_H
