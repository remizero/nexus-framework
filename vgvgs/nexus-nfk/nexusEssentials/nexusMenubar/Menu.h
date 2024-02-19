#ifndef MENU_H
#define MENU_H

// Librerías Internas
// Internal Libraries
#include "Menubar_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMenu>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_MENUBAR {

          class MENUBAR_EXPORT Menu : public QMenu {

              Q_OBJECT

            public :
              explicit Menu ( QWidget *parent = nullptr );

              void createStyle ();
          };
        }
      }
    }
  }

#endif // MENU_H
