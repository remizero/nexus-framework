#ifndef XSD_H
#define XSD_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "core/ElementAbs.h"
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

          class XSD_EXPORT Xsd: public QObject {

              Q_OBJECT
              Q_ENUMS ( indicatorEnum levelEnum )

            public :
              Xsd ();

              enum indicatorEnum {

                ALL = ElementAbs::elements::ALL,
                ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
                CHOICE = ElementAbs::elements::CHOICE,
                GROUP = ElementAbs::elements::GROUP,
                MAXOCCURS = PropertyAbs::properties::MAXOCCURS,
                MINOCCURS = PropertyAbs::properties::MINOCCURS,
                SEQUENCE = ElementAbs::elements::SEQUENCE

                // Aparentan ser otros indicadores
                //xs:union
                //xs:list
                //xs:mixed
              };
              Q_ENUM ( indicatorEnum )

              enum levelEnum {

                EMPTY = 0,
                ROOTFORM,
                TABFORM,
                GROUPFORM,
                PARAMFORM,
                TYPEFORM,
                VALUEFORM
              };
              Q_ENUM ( levelEnum )

              static int indexOfLevelEnum ( QString enumKey );
              static bool inLevelEmun ( QString enumKey );
              static QString levelEnumToString ( Xsd::levelEnum enumValue );
          };
        }
      }
    }
  }

#endif // XSD_H
