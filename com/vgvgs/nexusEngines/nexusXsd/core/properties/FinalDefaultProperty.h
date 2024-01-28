#ifndef FINALDEFAULTPROPERTY_H
#define FINALDEFAULTPROPERTY_H

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

          class XSD_EXPORT FinalDefaultProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: finalDefault = (#all | List of (extension | restriction | list | union))  : ''

            public :
              FinalDefaultProperty ( QString value = "" );
              FinalDefaultProperty ( const FinalDefaultProperty& );
              ~FinalDefaultProperty ();

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
Q_DECLARE_METATYPE ( NSLIB_XSD::FinalDefaultProperty )

#endif // FINALDEFAULTPROPERTY_H
