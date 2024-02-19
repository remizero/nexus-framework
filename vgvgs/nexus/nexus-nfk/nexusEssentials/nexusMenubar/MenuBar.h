#ifndef MENUBAR_H
#define MENUBAR_H

// Librerías Internas
// Internal Libraries
#include "Menubar_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías Externas
// External Libraries
#include "ExitAct.h"
#include "FullScreenAct.h"
#include "HelpTopicsAct.h"
#include "OnlineHelpAct.h"
#include "RestartAct.h"
#include "SettingsAct.h"
#include "StatusBarShowHideAct.h"
#include "ToolBarShowHideAct.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMenuBar>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MENUBAR {

          class MENUBAR_EXPORT MenuBar : public QMenuBar {

              Q_OBJECT

            public :
              explicit MenuBar ( QWidget *parent = nullptr  );
              ~MenuBar ();
          };
        }
      }
    }
  }

#endif // MENUBAR_H
