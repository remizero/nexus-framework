#include "AppExit.h"


using namespace NSLIB_CORE;


AppExit::AppExit ( QObject *parent ) : QObject ( parent ) {

  this->initialized = false;
}

void AppExit::initialize ( AppConfig *appConfig, UserConfig *userConfig ) {

  this->appConfig = appConfig;
  this->userConfig = userConfig;
  this->initialized = true;
}

void AppExit::saveSettings () {

  if ( this->initialized ) {

    /**
     * TODO Qué hacer aquí?
     */

  } else {

    qDebug () << "La clase AppExit no ha sido inicializa correctamente.";
  }
}

void AppExit::saveState ( QMainWindow *parent ) {

  if ( this->initialized ) {

    this->userConfig->getSettings ()->setValue ( "geometry", parent->saveGeometry () );
    this->userConfig->getSettings ()->setValue ( "windowState", parent->saveState () );

  } else {

    qDebug () << "La clase AppExit no ha sido inicializa correctamente.";
  }
}
