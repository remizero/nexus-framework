#ifndef TOOLBARSHOWHIDEACT_H
#define TOOLBARSHOWHIDEACT_H

// Librerías Internas
// Internal Libraries
#include "Actions_global.h"
#include "ActionAbs.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMainWindow>
#include <QToolBar>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_ACTIONS {

          class ACTIONS_EXPORT ToolBarShowHideAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE ToolBarShowHideAct ( QString title, QWidget *parent );

            public slots :
              void execAct () override;
          };
        }
      }
    }
  }
}

#endif // TOOLBARSHOWHIDEACT_H
