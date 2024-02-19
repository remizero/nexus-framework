#ifndef GROUP_H
#define GROUP_H

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

          class XSD_EXPORT Group : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE Group ();
              Group ( const Group& );
              ~Group ();

              enum content {

                ANNOTATION = ElementAbs::elements::ANNOTATION,
                ALL = ElementAbs::elements::ALL,
                CHOICE = ElementAbs::elements::CHOICE,
                SEQUENCE = ElementAbs::elements::SEQUENCE
              };
              Q_ENUM ( content )

              enum properties {

                ID = PropertyAbs::properties::ID,
                MAXOCCURS = PropertyAbs::properties::MAXOCCURS,
                MINOCCURS = PropertyAbs::properties::MINOCCURS,
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
Q_DECLARE_METATYPE ( NSLIB_XSD::Group )

#endif // GROUP_H
