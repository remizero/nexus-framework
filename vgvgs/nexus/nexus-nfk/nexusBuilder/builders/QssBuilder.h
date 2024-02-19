#ifndef QSSBUILDER_H
#define QSSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilderUtils.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries

// TODO Revisar https://doc.qt.io/qt-6/stylesheet-syntax.html
  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT QssBuilder : QObject {

            Q_OBJECT

          public :
            QssBuilder ( QObject *parent = nullptr );
            QString build ( QString resource );
        };
      }
    }
  }

#endif // QSSBUILDER_H
