#ifndef NAMEPROPERTY_H
#define NAMEPROPERTY_H

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

          class XSD_EXPORT NameProperty : public PropertyAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE NameProperty ( QString value = "" );
              Q_INVOKABLE NameProperty ( const NameProperty& );
              Q_INVOKABLE ~NameProperty ();

              Q_INVOKABLE QString getValue () const;
              Q_INVOKABLE void setValue ( const QString &value );

            private :
              Q_INVOKABLE QString value;
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::NameProperty )

#endif // NAMEPROPERTY_H
