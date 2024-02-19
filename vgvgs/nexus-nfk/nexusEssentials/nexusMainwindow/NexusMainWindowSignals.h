#ifndef NEXUSMAINWINDOWSIGNALS_H
#define NEXUSMAINWINDOWSIGNALS_H

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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MAINWINDOW_EXPORT NexusMainWindowSignals {

            public :
              NexusMainWindowSignals ( QMainWindow *parent );
              ~NexusMainWindowSignals ();

              QMainWindow *getParent () const;

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }

#endif // NEXUSMAINWINDOWSIGNALS_H
