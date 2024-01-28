#ifndef FORMPROPERTY_H
#define FORMPROPERTY_H

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


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT FormProperty : public PropertyAbs {

              Q_OBJECT
              Q_ENUMS ( values )

            public :
              FormProperty ( QString value = "unqualified" );
              FormProperty ( const FormProperty& );
              ~FormProperty ();

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
}
Q_DECLARE_METATYPE ( NSLIB_XSD::FormProperty )

#endif // FORMPROPERTY_H
