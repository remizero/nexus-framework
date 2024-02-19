#ifndef RESTARTACT_H
#define RESTARTACT_H

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

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_ACTIONS {

          class ACTIONS_EXPORT RestartAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE RestartAct ( QString title, QWidget *parent );

            public slots :
              void execAct () override;
          };
        }
      }
    }
  }

#endif // RESTARTACT_H
