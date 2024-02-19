#ifndef FIELD_H
#define FIELD_H

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT Field : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE Field ();
              Field ( const Field& );
              ~Field ();

              enum content {

                ANNOTATION = ElementAbs::elements::ANNOTATION
              };
              Q_ENUM ( content )

              enum properties {

                ID = PropertyAbs::properties::ID,
                XPATH = PropertyAbs::properties::XPATH,
                XPATHDEFAULTNAMESPACE = PropertyAbs::properties::XPATHDEFAULTNAMESPACE
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
Q_DECLARE_METATYPE ( NSLIB_XSD::Field )

#endif // FIELD_H
