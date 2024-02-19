#ifndef XSDATTRIBUTE_H
#define XSDATTRIBUTE_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/FacetAbs.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QList>
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ENGINES {

        namespace NS_XSD {

          class XSD_EXPORT XsdAttribute : public QObject {

              Q_OBJECT

            public :
              XsdAttribute ();

            private :
              QString name;
              QList<FacetAbs *> facetsList;
          };
        }
      }
    }
  }

#endif // XSDATTRIBUTE_H
