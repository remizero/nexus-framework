#include "AppCreator.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppCreator::AppCreator ( const QString &path ) {

  //this->path = path;
}

void AppCreator::createProject () {

  // TODO Crear el directorio de la aplicación.
  // TODO Crear el archivo .pro de la aplicación.
  // TODO Crear el archivo resources.qrc de la aplicación.
  // TODO Crear el archivo export.def de la aplicación.
  // TODO Crear el archivo main.cpp de la aplicación.
  // TODO Ajustar los valores de configuración del archivo config.xml de la aplicación.
  // TODO Crear el archivo MainWindow.(h/cpp/ui) de la aplicación.
  // TODO El archivo MainWindow de la aplicación debe heredar de la clase MainWindow de la librería mainwindow.
}

void AppCreator::createDirProject () {

  // Crea la carpeta de destino
  QDir destDir ( this->path );
  destDir.mkdir ( this->path );
}
