#ifndef SUBSTITUTIONGROUPPROPERTY_H
#define SUBSTITUTIONGROUPPROPERTY_H

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

          class XSD_EXPORT SubstitutionGroupProperty : public PropertyAbs {

              Q_OBJECT

            public :
              SubstitutionGroupProperty ( bool value = false );
              SubstitutionGroupProperty ( const SubstitutionGroupProperty& );
              ~SubstitutionGroupProperty ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::SubstitutionGroupProperty )

#endif // SUBSTITUTIONGROUPPROPERTY_H
