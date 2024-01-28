#ifndef ACTIONABS_H
#define ACTIONABS_H

// Librerías Internas
// Internal Libraries
#include "Actions_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "actionsystem/ActionInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QIcon>
#include <QKeySequence>
#include <QMetaType>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_ACTIONS {

          class ACTIONS_EXPORT ActionAbs : public QAction, public NSLIB_CORE::ActionInterface {

              Q_OBJECT
              Q_INTERFACES ( NSLIB_CORE::ActionInterface )

            public :
              explicit ActionAbs ( QString title, QWidget *parent = nullptr );

            public slots :
              virtual void execAct () override = 0;

            protected :
              QWidget *myParent;
          };
        }
      }
    }
  }
}

Q_DECLARE_METATYPE ( NSLIB_ACTIONS::ActionAbs * )

#endif // ACTIONABS_H
