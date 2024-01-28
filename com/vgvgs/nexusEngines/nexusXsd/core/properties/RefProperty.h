#ifndef REFPROPERTY_H
#define REFPROPERTY_H

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

          class XSD_EXPORT RefProperty : public PropertyAbs {

              Q_OBJECT

            public :
              RefProperty ( QString value = "" );
              RefProperty ( const RefProperty& );
              ~RefProperty ();

              QString getValue () const;
              void setValue ( const QString &value );

            private :
              QString value;
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::RefProperty )

#endif // REFPROPERTY_H
