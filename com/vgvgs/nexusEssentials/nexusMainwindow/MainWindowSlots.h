#ifndef MAINWINDOWSLOTS_H
#define MAINWINDOWSLOTS_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"
#include "MainWindow.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "appsystem/App.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QMainWindow>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MAINWINDOW_EXPORT MainWindowSlots {

            public :
              MainWindowSlots ( QMainWindow *parent );

              void slotReboot ();

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }
}

#endif // MAINWINDOWSLOTS_H
