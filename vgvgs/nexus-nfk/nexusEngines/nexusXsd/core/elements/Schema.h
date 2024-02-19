#ifndef SCHEMA_H
#define SCHEMA_H

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

          class XSD_EXPORT Schema : public ElementAbs {

              Q_OBJECT
              Q_ENUMS ( content properties )

            public :
              Q_INVOKABLE Schema ();
              Schema ( const Schema& );
              ~Schema ();

              enum content {

                ANNOTATION = ElementAbs::elements::ANNOTATION,
                ATTRIBUTE = ElementAbs::elements::ATTRIBUTE,
                ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
                COMPLEXTYPE = ElementAbs::elements::COMPLEXTYPE,
                DEFAULTOPENCONTENT = ElementAbs::elements::DEFAULTOPENCONTENT,
                ELEMENT = ElementAbs::elements::ELEMENT,
                GROUP = ElementAbs::elements::GROUP,
                IMPORT = ElementAbs::elements::IMPORT,
                INCLUDE = ElementAbs::elements::INCLUDE,
                NOTATION = ElementAbs::elements::NOTATION,
                OVERRIDE = ElementAbs::elements::OVERRIDE,
                REDEFINE = ElementAbs::elements::REDEFINE,
                SIMPLETYPE = ElementAbs::elements::SIMPLETYPE
              };
              Q_ENUM ( content )

              enum properties {

                ATTRIBUTEFORMDEFAULT = PropertyAbs::properties::ATTRIBUTEFORMDEFAULT,
                BLOCKDEFAULT = PropertyAbs::properties::BLOCKDEFAULT,
                DEFAULTATTRIBUTES = PropertyAbs::properties::DEFAULTATTRIBUTES,
                ELEMENTFORMDEFAULT = PropertyAbs::properties::ELEMENTFORMDEFAULT,
                FINALDEFAULT = PropertyAbs::properties::FINALDEFAULT,
                ID = PropertyAbs::properties::ID,
                TARGETNAMESPACE = PropertyAbs::properties::TARGETNAMESPACE,
                VERSION = PropertyAbs::properties::VERSION,
                XMLLANG = PropertyAbs::properties::XMLLANG,
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
Q_DECLARE_METATYPE ( NSLIB_XSD::Schema )

#endif // SCHEMA_H
