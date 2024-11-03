// Librerías Internas
// Internal Libraries
// #include "MainWindow.h"
// #include "ACRegisterClasses.h"

// Librerías Externas
// External Libraries
#include "appsystem/AppManager.h"
#include "NexusDocumentation.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCoreApplication>
#include <QDebug>

// Librerías C++
// C++ Libraries


int main ( int argc, char *argv [] ) {

  // TODO 1-. Agregar el sistema DOXYGEN y ver como enlazarlo con la wiki de github.

  // NSLIB_CORE::AppManager::getInstance ()->create ( argc, argv );
  // NSLIB_CORE::AppManager::getInstance ()->initialize ();
  // // RegisterClasses::getInstance ()->addTypeClass ();
  // // if ( NSLIB_CORE::AppManager::getInstance ()->isGuiApp () ) {

  // //   MainWindow w;
  // //   return NSLIB_CORE::AppManager::getInstance ()->execute ( &w );

  // // } else {

  // return NSLIB_CORE::AppManager::getInstance ()->execute ();
  // }


  QCoreApplication a ( argc, argv );

  if ( argc < 2 ) {
    qDebug () << "Uso: commGen /ruta/del/directorio";
    a.exit ( 1 );
    return 1;
  }

  NSLIB_DOCUMENTATION::NexusDocumentation documentation;
  QString directoryPath = argv [ 1 ];
  if ( !documentation.isValidDirectory ( directoryPath ) ) {

    qDebug () << "La ruta del directorio proporcionada no es válida o no existe.";
    a.exit ( 1 );
    return 1;

  } else {

    qDebug () << directoryPath;
  }
  documentation.getFileList ( directoryPath );
  documentation.iterateFileList ();
  // readFilesInDirectory ( directoryPath );
  a.quit ();

  return a.exec ();
}
