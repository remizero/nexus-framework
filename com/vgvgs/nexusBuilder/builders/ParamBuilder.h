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
            ParamBuilder ( QString paramName, QString paramType, bool paramDynamic, bool paramNullPointer, QString paramDefaultValue = "" );

            void build ();

            const QString &getDefaultValue () const;
            const QString &getName () const;
            const QString &getParam () const;
            const QString &getType () const;
            bool isDynamic () const;
            bool isNullPointer () const;

          protected :
            QString defaultValue;
               bool dynamic;
            QString name;
               bool nullPointer;
            QString param;
            QString type;
        };
      }
    }
  }
}

#endif // PARAMBUILDER_H
