#ifndef NEXUSMAINWINDOW_H
#define NEXUSMAINWINDOW_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"
#include "NexusMainWindowEvents.h"
#include "NexusMainWindowSignals.h"
#include "NexusMainWindowSlots.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "appsystem/AppInit.h"
#include "appsystem/AppPaths.h"
#include "MenuBar.h"
#include "StatusBar.h"
#include "SystemTrayIcon.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QDebug>
#include <QEvent>
#include <QMainWindow>
#include <QResizeEvent>
#include <QSettings>
#include <QSystemTrayIcon>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class NexusMainWindowEvents;
          class NexusMainWindowSlots;

          class MAINWINDOW_EXPORT NexusMainWindow : public QMainWindow {

              Q_OBJECT

            public :
              explicit NexusMainWindow ( QSettings *settings, QWidget *parent = nullptr );
              ~NexusMainWindow ();

              // static int const EXIT_CODE_REBOOT = -123456789;

              NexusMainWindowSlots *getMainWindowSlots () const;
              QSystemTrayIcon *getSysTrayIcon () const;
              void setVisible ( bool visible ) override;

            public slots :
              void iconActivated ( QSystemTrayIcon::ActivationReason reason );

            protected :
              void centerWindow ();
              virtual void changeEvent( QEvent *event ) override;
              void closeEvent ( QCloseEvent *event ) override;
              void createMenuBar ();
              void createStatusBar ();
              void init ( QSettings *settings );
              void loadSettins ();
              void resizeEvent ( QResizeEvent *event ) override;
              void saveSettings ();
              void setMinimunWindowSize ();

            private :
                             NexusMainWindowEvents *mainWindowEvents;
                            NexusMainWindowSignals *mainWindowSignals;
                              NexusMainWindowSlots *mainWindowSlots;
              NSLIB_SYSTEMTRAYICON::SystemTrayIcon *sysTrayIcon;

              void createSysTrayIcon ();
          };
        }
      }
    }
  }

#endif // NEXUSMAINWINDOW_H
