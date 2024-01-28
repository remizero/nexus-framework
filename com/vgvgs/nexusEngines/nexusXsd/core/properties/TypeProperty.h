#ifndef TYPEPROPERTY_H
#define TYPEPROPERTY_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"

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

          class XSD_EXPORT TypeProperty : public PropertyAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE TypeProperty ( QString value = "" );
              Q_INVOKABLE TypeProperty ( const TypeProperty& );
              Q_INVOKABLE ~TypeProperty ();

              Q_INVOKABLE TypeAbs::types getValue () const;
              Q_INVOKABLE void setValue ( const QString value );
              Q_INVOKABLE void setValue ( TypeAbs::types value );
              Q_INVOKABLE int toInt ();
              Q_INVOKABLE QString toString ();

            private :
              TypeAbs::types value;
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::TypeProperty )

#endif // TYPEPROPERTY_H
