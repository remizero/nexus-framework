#ifndef ELEMENT_H
#define ELEMENT_H

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

          class XSD_EXPORT Element : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE Element ();
              Q_INVOKABLE Element ( const Element& );
              Q_INVOKABLE ~Element ();

              enum content {

                ALTERNATIVE = ElementAbs::elements::ALTERNATIVE,
                ANNOTATION = ElementAbs::elements::ANNOTATION,
                COMPLEXTYPE = ElementAbs::elements::COMPLEXTYPE,
                KEY = ElementAbs::elements::KEY,
                KEYREF = ElementAbs::elements::KEYREF,
                SIMPLETYPE = ElementAbs::elements::SIMPLETYPE,
                UNIQUE = ElementAbs::elements::UNIQUE
              };
              Q_ENUM ( content )

              enum properties {

                ABSTRACT = PropertyAbs::properties::ABSTRACT,
                BLOCK = PropertyAbs::properties::BLOCK,
                DEFAULT = PropertyAbs::properties::DEFAULT,
                FINAL = PropertyAbs::properties::FINAL,
                FIXED = PropertyAbs::properties::FIXED,
                FORM = PropertyAbs::properties::FORM,
                ID = PropertyAbs::properties::ID,
                MAXOCCURS = PropertyAbs::properties::MAXOCCURS,
                MINOCCURS = PropertyAbs::properties::MINOCCURS,
                NAME = PropertyAbs::properties::NAME,
                NILLABLE = PropertyAbs::properties::NILLABLE,
                REF = PropertyAbs::properties::REF,
                SUBSTITUTIONGROUP = PropertyAbs::properties::SUBSTITUTIONGROUP,
                TARGETNAMESPACE = PropertyAbs::properties::TARGETNAMESPACE,
                TYPE = PropertyAbs::properties::TYPE
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
Q_DECLARE_METATYPE ( NSLIB_XSD::Element )

#endif // ELEMENT_H
