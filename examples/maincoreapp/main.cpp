#include "MainWindow.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#include <QtCore/QCoreApplication>
#else
#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#endif

#include "appsystem/AppManager.h"

int main ( int argc, char *argv [] ) {

  // TODO
  // 1-. ( LISTO ) Todo arranca con la carga del recurso de configuración de la aplicación
  // principal. Ahí se encuentra el valor que definirá si la aplicación será de
  // tipo GUI o Consola.
  // 2-. ( LISTO ) Verificar si vienen argumentos en int main ( int argc, char *argv [] ) {
  // 3-. ( LISTO ) Validar cuales son los permitidos para aplicaciones GUI y para consola.
  // 4-. ( LISTO ) Permitir agregar comandos adicionales para la comprobación anterior.
  // 5-. ( LISTO ) Estudiar la conveniencia de agregar estos comandos vía archivo de
  // configuración o vía programación.
  // 6-. Agregar el sistema DOXYGEN y ver como enlazarlo con la wiki de github.


  NAMESPACE_LIBRARY_CORE::AppManager::getInstance ()->create ( argc, argv );
  NAMESPACE_LIBRARY_CORE::AppManager::getInstance ()->initialize ();
  MainWindow w; // TODO Aquí está el error. Como crear esta instancia dentro del método execute?
  return NAMESPACE_LIBRARY_CORE::AppManager::getInstance ()->execute ( argc, argv, &w );
}
