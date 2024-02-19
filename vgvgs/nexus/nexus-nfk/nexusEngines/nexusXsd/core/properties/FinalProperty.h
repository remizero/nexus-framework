#ifndef FINALPROPERTY_H
#define FINALPROPERTY_H

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

          class XSD_EXPORT FinalProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: para complextype
              // final = (#all | List of (extension | restriction))
              // TODO: para element
              // final = (#all | List of (extension | restriction))
              // TODO: para schema
              // finalDefault = (#all | List of (extension | restriction | list | union))  : ''
              // TODO: para simpletype
              // final = (#all | List of (list | union | restriction | extension))

            public :
              FinalProperty ( QString value = "" );
              FinalProperty ( const FinalProperty& );
              ~FinalProperty ();

              QString getValue () const;
              void setValue ( const QString &value );

            private :
              QString value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::FinalProperty )

#endif // FINALPROPERTY_H
