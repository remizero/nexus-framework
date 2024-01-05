#ifndef CLASSBUILDER_H
#define CLASSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "AttributeBuilder.h"
#include "MethodBuilder.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QList>
#include <QObject>

// Librerías C++
// C++ Libraries
#include <algorithm>


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ClassBuilder {

          public :
            ClassBuilder ();

            QString build ();

            const QList<AttributeBuilder *> &getAttributeList () const;
            const QList<MethodBuilder *> &getMethodList () const;
            const QList<QString *> &getNamespaceList() const;
            void setAttributeList ( AttributeBuilder *attribute );
            void setMethodList ( MethodBuilder *method );
            void setNamespaceList ( QString *nameSpace );

          private :
            QList<AttributeBuilder *> attributeList;
            QList<MethodBuilder *> methodList;
            QList<QString *> namespaceList;
        };
      }
    }
  }
}

#endif // CLASSBUILDER_H
