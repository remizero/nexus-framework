#ifndef HELPTOPICSACT_H
#define HELPTOPICSACT_H

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

          class ACTIONS_EXPORT HelpTopicsAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE HelpTopicsAct ( QString title, QWidget *parent );

            public slots :
              void execAct () override;
          };
        }
      }
    }
  }

#endif // HELPTOPICSACT_H
