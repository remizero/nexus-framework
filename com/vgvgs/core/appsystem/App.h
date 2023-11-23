#ifndef APP_H
#define APP_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppInit.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QDebug>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_CORE {

      class CORE_EXPORT App : public QApplication {

          Q_OBJECT

        public :
          App ( int &argc, char **argv );
          virtual ~App ();

          static int const EXIT_CODE_REBOOT = -123456789;

          bool notify ( QObject *receiver, QEvent *event ) override;
      };
    }
  }
}

#endif // APP_H
