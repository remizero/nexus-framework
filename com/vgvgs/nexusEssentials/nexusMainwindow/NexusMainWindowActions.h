#ifndef NEXUSMAINWINDOWACTIONS_H
#define NEXUSMAINWINDOWACTIONS_H

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

          class MAINWINDOW_EXPORT NexusMainWindowActions {

            public :
              NexusMainWindowActions ( QMainWindow *parent );
              ~NexusMainWindowActions ();

              virtual void createActions () = 0;
              QMainWindow *getParent () const;
              void loadBasicActions ();
              void loadPluginActions ();
              void setPluginAction ();

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }
}

#endif // NEXUSMAINWINDOWACTIONS_H
