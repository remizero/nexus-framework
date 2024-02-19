#ifndef NOTNAMESPACEPROPERTY_H
#define NOTNAMESPACEPROPERTY_H

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

          class XSD_EXPORT NotNamespaceProperty : public PropertyAbs {

              Q_OBJECT

            public :
              NotNamespaceProperty ( bool value = false );
              NotNamespaceProperty ( const NotNamespaceProperty& );
              ~NotNamespaceProperty ();

              bool getValue () const;
              void setValue ( bool value );

            private :
              bool value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::NotNamespaceProperty )

#endif // NOTNAMESPACEPROPERTY_H
