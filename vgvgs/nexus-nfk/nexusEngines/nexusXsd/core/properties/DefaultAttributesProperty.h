#ifndef DEFAULTATTRIBUTESPROPERTY_H
#define DEFAULTATTRIBUTESPROPERTY_H

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

          class XSD_EXPORT DefaultAttributesProperty : public PropertyAbs {

              Q_OBJECT

            public :
              DefaultAttributesProperty ( QString value = "" );
              DefaultAttributesProperty ( const DefaultAttributesProperty& );
              ~DefaultAttributesProperty ();

              QString getValue () const;
              void setValue ( const QString &value );

            private :
              QString value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::DefaultAttributesProperty )

#endif // DEFAULTATTRIBUTESPROPERTY_H
