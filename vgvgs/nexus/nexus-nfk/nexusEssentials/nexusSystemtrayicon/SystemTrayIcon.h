#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

// Librerías Internas
// Internal Libraries
#include "Systemtrayicon_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías Externas
// External Libraries
#include "appsystem/AppInit.h"
#include "appsystem/AppPaths.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QCoreApplication>
#include <QDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_SYSTEMTRAYICON {

          class SYSTEMTRAYICON_EXPORT SystemTrayIcon : public QSystemTrayIcon {

              Q_OBJECT

            public :
              explicit SystemTrayIcon ( QObject *parent = nullptr );

              void setVisible ( bool visible );

            private :
                  QAction *maximizeAction;
                  QAction *minimizeAction;
              QMainWindow *parent;
                  QAction *quitAction;
                  QAction *restoreAction;
                    QMenu *trayIconMenu;

              void createActions ();
              void createMenu ();
          };
        }
      }
    }
  }

#endif // SYSTEMTRAYICON_H
