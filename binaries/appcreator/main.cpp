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

  // TODO 1-. ( LISTO ) Todo arranca con la carga del recurso de configuración de la aplicación
  // principal. Ahí se encuentra el valor que definirá si la aplicación será de
  // tipo GUI o Consola.
  // 2-. Verificar si vienen argumentos en int main ( int argc, char *argv [] ) {
  // 3-. ( LISTO ) Validar cuales son los permitidos para aplicaciones GUI y para consola.
  // 4-. ( LISTO ) Permitir agregar comandos adicionales para la comprobación anterior.
  // 5-. ( LISTO ) Estudiar la conveniencia de agregar estos comandos vía archivo de
  // configuración o vía programación.
  // 6-. Agregar el sistema DOXYGEN y ver como enlazarlo con la wiki de github.

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
