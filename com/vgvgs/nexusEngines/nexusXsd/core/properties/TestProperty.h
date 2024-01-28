#ifndef TESTPROPERTY_H
#define TESTPROPERTY_H

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

          class XSD_EXPORT TestProperty : public PropertyAbs {

              Q_OBJECT

            public :
              TestProperty ( bool value = false );
              TestProperty ( const TestProperty& );
              ~TestProperty ();

              bool getValue () const;
              void setValue ( bool value );

            private :
              bool value;
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::TestProperty )

#endif // TESTPROPERTY_H
