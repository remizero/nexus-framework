#ifndef MAINWINDOWSIGNALS_H
#define MAINWINDOWSIGNALS_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"

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


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MAINWINDOW_EXPORT MainWindowSignals {

            public :
              MainWindowSignals ( QMainWindow *parent );

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }
}

#endif // MAINWINDOWSIGNALS_H
