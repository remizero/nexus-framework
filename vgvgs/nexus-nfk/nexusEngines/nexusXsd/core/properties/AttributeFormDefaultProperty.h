#ifndef ATTRIBUTEFORMDEFAULTPROPERTY_H
#define ATTRIBUTEFORMDEFAULTPROPERTY_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/PropertyAbs.h"

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

          class XSD_EXPORT AttributeFormDefaultProperty : public PropertyAbs {

              Q_OBJECT
              Q_ENUMS ( values )

            public :
              AttributeFormDefaultProperty ( QString value = "unqualified" );
              AttributeFormDefaultProperty ( const AttributeFormDefaultProperty& );
              ~AttributeFormDefaultProperty ();

              enum values {

                QUALIFIED = 1,
                UNQUALIFIED
              };
              Q_ENUM ( values )

              QString getValue () const;
              static int indexOfValuesEnum ( QString enumKey );
              static bool inValuesEmun ( QString enumKey );
              void setValue ( QString value );
              static QString valuesEnumToString ( values enumValue );

            private :
              QString value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::AttributeFormDefaultProperty )

#endif // ATTRIBUTEFORMDEFAULTPROPERTY_H
