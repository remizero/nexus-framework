#ifndef MAXOCCURSPROPERTY_H
#define MAXOCCURSPROPERTY_H

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

          class XSD_EXPORT MaxOccursProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: para all
              // maxOccurs = (0 | 1) : 1
              // TODO: para any
              // maxOccurs = (nonNegativeInteger | unbounded)  : 1
              // TODO: para choice
              // maxOccurs = (nonNegativeInteger | unbounded)  : 1
              // TODO: para element
              // maxOccurs = (nonNegativeInteger | unbounded)  : 1
              // TODO: para group
              // maxOccurs = (nonNegativeInteger | unbounded)  : 1
              // TODO: para sequence
              // maxOccurs = (nonNegativeInteger | unbounded)  : 1

            public :
              MaxOccursProperty ( bool value = false );
              MaxOccursProperty ( const MaxOccursProperty& );
              ~MaxOccursProperty ();

              bool getValue () const;
              void setValue ( bool value );

            private :
              bool value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::MaxOccursProperty )

#endif // MAXOCCURSPROPERTY_H
