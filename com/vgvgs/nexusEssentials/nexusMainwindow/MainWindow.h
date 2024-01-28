#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Librerías Internas
// Internal Libraries
#include "Mainwindow_global.h"
#include "MainWindowEvents.h"
#include "MainWindowSignals.h"
#include "MainWindowSlots.h"

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


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MAINWINDOW {

          class MainWindowEvents;
          class MainWindowSlots;

          class MAINWINDOW_EXPORT MainWindow : public QMainWindow {

              Q_OBJECT

            public :
              explicit MainWindow ( QSettings *settings, QWidget *parent = nullptr );
              ~MainWindow ();

              // static int const EXIT_CODE_REBOOT = -123456789;

              MainWindowSlots *getMainWindowSlots () const;
              QSystemTrayIcon *getSysTrayIcon () const;
              void setVisible ( bool visible ) Q_DECL_OVERRIDE;

            public slots :
              void iconActivated ( QSystemTrayIcon::ActivationReason reason );

            protected :
              void centerWindow ();
              virtual void changeEvent( QEvent *event ) Q_DECL_OVERRIDE;
              void closeEvent ( QCloseEvent *event ) Q_DECL_OVERRIDE;
              void createMenuBar ();
              void createStatusBar ();
              void init ( QSettings *settings );
              void loadSettins ();
              void resizeEvent ( QResizeEvent *event ) Q_DECL_OVERRIDE;
              void saveSettings ();
              void setMinimunWindowSize ();

            private :
                                  MainWindowEvents *mainWindowEvents;
                                 MainWindowSignals *mainWindowSignals;
                                   MainWindowSlots *mainWindowSlots;
              NSLIB_SYSTEMTRAYICON::SystemTrayIcon *sysTrayIcon;

              void createSysTrayIcon ();
          };
        }
      }
    }
  }
}

#endif // MAINWINDOW_H
