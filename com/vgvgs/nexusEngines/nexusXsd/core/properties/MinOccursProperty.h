#ifndef MINOCCURSPROPERTY_H
#define MINOCCURSPROPERTY_H

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

          class XSD_EXPORT MinOccursProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: para all
              // minOccurs = (0 | 1) : 1
              // TODO: para any
              // minOccurs = nonNegativeInteger : 1
              // TODO: para choice
              // minOccurs = nonNegativeInteger : 1
              // TODO: para element
              // minOccurs = nonNegativeInteger : 1
              // TODO: para group
              // minOccurs = nonNegativeInteger : 1
              // TODO: para sequence
              // minOccurs = nonNegativeInteger : 1

            public :
              MinOccursProperty ( bool value = false );
              MinOccursProperty ( const MinOccursProperty& );
              ~MinOccursProperty ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::MinOccursProperty )

#endif // MINOCCURSPROPERTY_H
