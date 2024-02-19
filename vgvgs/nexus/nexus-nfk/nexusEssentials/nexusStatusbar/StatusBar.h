#ifndef STATUSBAR_H
#define STATUSBAR_H

// Librerías Internas
// Internal Libraries
#include "Statusbar_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QStatusBar>
#include <QLabel>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_STATUSBAR {

          class STATUSBAR_EXPORT StatusBar : public QStatusBar {

            public :
              explicit StatusBar ( QWidget *parent = nullptr );
              ~StatusBar ();

              void addNewSection ();
              void hideSection ();
              void showSection ();

          };
        }
      }
    }
  }

#endif // STATUSBAR_H
