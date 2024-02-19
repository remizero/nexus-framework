#ifndef NAMESPACEPROPERTY_H
#define NAMESPACEPROPERTY_H

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

          class XSD_EXPORT NamespaceProperty : public PropertyAbs {

              Q_OBJECT
              // TODO: para any
              // namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
              // TODO: para anyattribute
              // namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
              // TODO: para import
              // namespace = anyURI

            public :
              NamespaceProperty ( QString value = "" );
              NamespaceProperty ( const NamespaceProperty& );
              ~NamespaceProperty ();

              QString getValue () const;
              void setValue ( const QString &value );

            private :
              QString value;
          };
        }
      }
    }
  }
Q_DECLARE_METATYPE ( NSLIB_XSD::NamespaceProperty )

#endif // NAMESPACEPROPERTY_H
