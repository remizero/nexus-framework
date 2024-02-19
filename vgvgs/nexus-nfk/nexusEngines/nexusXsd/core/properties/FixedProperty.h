#ifndef FIXEDPROPERTY_H
#define FIXEDPROPERTY_H

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

          class XSD_EXPORT FixedProperty : public PropertyAbs {

              Q_OBJECT

            public :
              FixedProperty ( QString value = "" );
              FixedProperty ( const FixedProperty& );
              ~FixedProperty ();

              QString getValue () const;
              void setValue ( const QString &value );

            private :
              QString value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::FixedProperty )

#endif // FIXEDPROPERTY_H
