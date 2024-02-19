#ifndef PROCESSCONTENTSPROPERTY_H
#define PROCESSCONTENTSPROPERTY_H

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

          class XSD_EXPORT ProcessContentsProperty : public PropertyAbs {

              Q_OBJECT

            public :
              ProcessContentsProperty ( bool value = false );
              ProcessContentsProperty ( const ProcessContentsProperty& );
              ~ProcessContentsProperty ();

              bool getValue () const;
              void setValue ( bool value );

            private :
              bool value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::ProcessContentsProperty )

#endif // PROCESSCONTENTSPROPERTY_H
