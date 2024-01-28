#ifndef NEXUSMAINWINDOWEVENTS_H
#define NEXUSMAINWINDOWEVENTS_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"
#include "NexusMainWindow.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "appsystem/AppInit.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCloseEvent>
#include <QEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QResizeEvent>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MAINWINDOW_EXPORT NexusMainWindowEvents {

            public :
              NexusMainWindowEvents ( QMainWindow *parent );
              ~NexusMainWindowEvents ();

              void adjustMaximizedSize ( QMainWindow *parent );
              void adjustMinimizedSize ( QMainWindow *parent );
              void changeEvent( QEvent *event );
              void closeEvent ( QCloseEvent *event );
              QMainWindow *getParent () const;
              void resizeEvent ( QResizeEvent *event );

            private :
              QMainWindow *parent;
          };
        }
      }
    }
  }
}

#endif // NEXUSMAINWINDOWEVENTS_H
