#ifndef ACTIONABS_H
#define ACTIONABS_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "actionsystem/ActionInterface.h"

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QIcon>
#include <QKeySequence>
#include <QMetaType>


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_CORE {

      class CORE_EXPORT ActionAbs : public QAction, public ActionInterface {

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

Q_DECLARE_METATYPE ( NSLIB_CORE::ActionAbs * )

#endif // ACTIONABS_H
