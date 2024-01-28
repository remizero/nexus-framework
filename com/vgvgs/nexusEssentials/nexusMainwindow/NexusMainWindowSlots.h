#ifndef NEXUSMAINWINDOWSLOTS_H
#define NEXUSMAINWINDOWSLOTS_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"
#include "NexusMainWindow.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "appsystem/App.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QDebug>
#include <QMainWindow>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MAINWINDOW_EXPORT NexusMainWindowSlots {

            public :
              NexusMainWindowSlots ( QMainWindow *parent );
              ~NexusMainWindowSlots ();

              QMainWindow *getParent () const;
              void slotReboot ();

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }
}

#endif // NEXUSMAINWINDOWSLOTS_H
