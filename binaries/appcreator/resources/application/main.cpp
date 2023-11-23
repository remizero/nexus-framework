// Librerías Internas
// Internal Libraries
#include "MainWindow.h"
#include "RegisterClasses.h"

// Librerías Externas
// External Libraries
#include "appsystem/AppManager.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


int main ( int argc, char *argv [] ) {

  NSLIB_CORE::AppManager::getInstance ()->create ( argc, argv );
  NSLIB_CORE::AppManager::getInstance ()->initialize ();
  RegisterClasses::getInstance ()->addTypeClass ();
  if ( NSLIB_CORE::AppManager::getInstance ()->isGuiApp () ) {

    MainWindow w;
    return NSLIB_CORE::AppManager::getInstance ()->execute ( &w );

  } else {

    return NSLIB_CORE::AppManager::getInstance ()->execute ();
  }
}
