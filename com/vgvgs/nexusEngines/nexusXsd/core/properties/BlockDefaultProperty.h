#ifndef BLOCKDEFAULTPROPERTY_H
#define BLOCKDEFAULTPROPERTY_H

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

          class XSD_EXPORT BlockDefaultProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: blockDefault = (#all | List of (extension | restriction | substitution))  : ''
              // Como manejar este tipo de valor.

            public :
              BlockDefaultProperty ( QString value = "" );
              BlockDefaultProperty ( const BlockDefaultProperty& );
              ~BlockDefaultProperty ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::BlockDefaultProperty )

#endif // BLOCKDEFAULTPROPERTY_H
