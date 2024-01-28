#ifndef TYPEABS_H
#define TYPEABS_H

// Librerías Internas
// Internal Libraries
#include "Xsd_global.h"
#include "FacetAbs.h"
#include "Xsd.h"

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

          class XSD_EXPORT TypeAbs : public QObject {

              Q_OBJECT
              Q_ENUMS ( types )

            public :
              Q_INVOKABLE TypeAbs ();
              TypeAbs ( const TypeAbs& );
              ~TypeAbs ();

              enum types {

                USER = 0,
                ANYURI, //
                BASE64BINARY, //
                BOOLEAN, //
                BYTE, //	A signed 8-bit integer
                DATE, //	Defines a date value
                DATETIME, //	Defines a date and time value
                DATETIMESTAMP,
                DAYTIMEDURATION,
                DECIMAL, //	A decimal value
                DOUBLE, //
                DURATION, //	Defines a time interval
                ENTITIES, //
                ENTITY, //
                FLOAT, //
                GDAY, //	Defines a part of a date - the day (DD)
                GMONTH, //	Defines a part of a date - the month (MM)
                GMONTHDAY, //	Defines a part of a date - the month and day (MM-DD)
                GYEAR, //	Defines a part of a date - the year (YYYY)
                GYEARMONTH, //	Defines a part of a date - the year and month (YYYY-MM)
                HEXBINARY, //
                ID, //	A string that represents the ID attribute in XML (only used with schema attributes)
                IDREF, //	A string that represents the IDREF attribute in XML (only used with schema attributes)
                IDREFS, //
                INT, //	A signed 32-bit integer
                INTEGER, //	An integer value
                LANGUAGE, //	A string that contains a valid language id
                LONG, //	A signed 64-bit integer
                NAME, //	A string that contains a valid XML name
                NCNAME, //
                NEGATIVEINTEGER, //	An integer containing only negative values (..,-2,-1)
                NMTOKEN, //	A string that represents the NMTOKEN attribute in XML (only used with schema attributes)
                NMTOKENS, //
                NONNEGATIVEINTEGER, //	An integer containing only non-negative values (0,1,2,..)
                NONPOSITIVEINTEGER, //	An integer containing only non-positive values (..,-2,-1,0)
                NORMALIZEDSTRING, //	A string that does not contain line feeds, carriage returns, or tabs
                NOTATION, //
                POSITIVEINTEGER, //	An integer containing only positive values (1,2,..)
                QNAME, //
                SHORT, //	A signed 16-bit integer
                STRING, //	A string
                TIME, //	Defines a time value
                TOKEN, //	A string that does not contain line feeds, carriage returns, tabs, leading or trailing spaces, or multiple spaces
                UNSIGNEDBYTE, //	An unsigned 8-bit integer
                UNSIGNEDINT, //	An unsigned 32-bit integer
                UNSIGNEDLONG, //	An unsigned 64-bit integer
                UNSIGNEDSHORT, //	An unsigned 16-bit integer
                YEARMONTHDURATION
              };
              Q_ENUM ( types )

              Q_INVOKABLE static int indexOfEnum ( QString enumKey );
              Q_INVOKABLE static bool inEmun ( QString enumKey );
              Q_INVOKABLE static QString enumToString ( types enumValue );
          };
        }
      }
    }
  }
}
Q_DECLARE_METATYPE ( NSLIB_XSD::TypeAbs )

#endif // TYPEABS_H
