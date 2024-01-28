#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

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

          class XSD_EXPORT ComplexType : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE ComplexType ();
              ComplexType ( const ComplexType& );
              ~ComplexType ();

              enum content {

                ALL = ElementAbs::elements::ALL,
                ANNOTATION = ElementAbs::elements::ANNOTATION,
                ANYATTRIBUTE = ElementAbs::elements::ANYATTRIBUTE,
                ATTRIBUTE = ElementAbs::elements::ATTRIBUTE,
                ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
                ASSERT = ElementAbs::elements::ASSERT,
                CHOICE = ElementAbs::elements::CHOICE,
                COMPLEXCONTENT = ElementAbs::elements::COMPLEXCONTENT,
                GROUP = ElementAbs::elements::GROUP,
                OPENCONTENT = ElementAbs::elements::OPENCONTENT,
                SEQUENCE = ElementAbs::elements::SEQUENCE,
                SIMPLECONTENT = ElementAbs::elements::SIMPLECONTENT
              };
              Q_ENUM ( content )

              enum properties {

                ABSTRACT = PropertyAbs::properties::ABSTRACT,
                DEFAULTATTRIBUTESAPPLY = PropertyAbs::properties::DEFAULTATTRIBUTESAPPLY,
                BLOCK = PropertyAbs::properties::BLOCK,
                FINAL = PropertyAbs::properties::FINAL,
                ID = PropertyAbs::properties::ID,
                MIXED = PropertyAbs::properties::MIXED,
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
Q_DECLARE_METATYPE ( NSLIB_XSD::ComplexType )

#endif // COMPLEXTYPE_H
