#ifndef PARAMBUILDER_H
#define PARAMBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ParamBuilder {

          public :
            ParamBuilder ();

            QString build ();

            const QString &getName () const;
            const QString &getParam () const;
            const QString &getType () const;
            const QString &getDefaultValue () const;
            void setName ( const QString &newName );
            void setParam ( const QString &newParam );
            void setType ( const QString &newType );
            void setDefaultValue ( const QString &newDefaultValue );

          protected :
            QString name;
            QString param;
            QString type;
            QString defaultValue;
        };
      }
    }
  }
}

#endif // PARAMBUILDER_H
