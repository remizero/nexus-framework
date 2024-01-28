#ifndef BLOCKPROPERTY_H
#define BLOCKPROPERTY_H

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

          class XSD_EXPORT BlockProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: Para Element
              // block = (#all | List of (extension | restriction | substitution))
              // TODO: Para ComplexType
              // block = (#all | List of (extension | restriction))

            public :
              BlockProperty ( QString value = "" );
              BlockProperty ( const BlockProperty& );
              ~BlockProperty ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::BlockProperty )

#endif // BLOCKPROPERTY_H
