#include "AppInit.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppInit::AppInit ( QObject *parent ) : QObject ( parent ) {

  this->initialized = false;
}

bool AppInit::checkVersion () {

  bool checkVersion = false;
  if ( this->initialized ) {

//            checkVersion = ( QT_VERSION >= QT_VERSION_CHECK ( this->appConfig->getSettings ()->value ( "app/mayorversion" ).toInt (), this->appConfig->getSettings ()->value ( "app/minorversion" ).toInt (), this->appConfig->getSettings ()->value ( "app/pathversion" ).toInt () ) );
    if ( ( checkVersion = ( QT_VERSION >= QT_VERSION_CHECK ( this->appConfig->getSettings ()->value ( "app/mayorversion" ).toInt (), this->appConfig->getSettings ()->value ( "app/minorversion" ).toInt (), this->appConfig->getSettings ()->value ( "app/pathversion" ).toInt () ) ) ) ) {

      if ( this->appConfig->getSettings ()->value ( "app/typeApp" ).toString () == "gui" ) {

        QMessageBox msgBox (
              QMessageBox::Warning,
              this->appConfig->getSettings ()->value ( "app/applicationdisplayname" ).toString (),
              "Debe tener instalada una versión de Qt igual o superior " + this->appConfig->getSettings ()->value ( "app/mayorversion" ).toString () + "." + this->appConfig->getSettings ()->value ( "app/minorversion" ).toString () + "." + this->appConfig->getSettings ()->value ( "app/pathversion" ).toString () + ".",
              QMessageBox::Ok );
        msgBox.exec ();

      } else {

        // TODO Como mostrar el mensaje por consola.
        qDebug () << this->appConfig->getSettings ()->value ( "app/applicationdisplayname" ).toString () <<  "Debe tener instalada una versión de Qt igual o superior " + this->appConfig->getSettings ()->value ( "app/mayorversion" ).toString () + "." + this->appConfig->getSettings ()->value ( "app/minorversion" ).toString () + "." + this->appConfig->getSettings ()->value ( "app/pathversion" ).toString () + ".";
      }
    }
  } else {

    qDebug () << "La clase AppInit no ha sido inicializa correctamente.";
  }
  return checkVersion;
}

AppConfig *AppInit::getAppConfig () const {

  return this->appConfig;
}

UserConfig *AppInit::getUserConfig () const {

  return this->userConfig;
}

void AppInit::initialize ( AppConfig *appConfig, UserConfig *userConfig ) {

  this->appConfig = appConfig;
  this->userConfig = userConfig;
  this->initialized = true;
}

bool AppInit::restoreDockWidget ( QMainWindow *parent , QDockWidget *dockWidget ) {

  if ( this->initialized ) {

    // TODO Como obtener los valores del dockwidget.
    return parent->restoreDockWidget ( dockWidget );

  } else {

    qDebug () << "La clase AppInit no ha sido inicializa correctamente.";
    return false;
  }
}

bool AppInit::restoreGeometry ( QMainWindow *parent ) {

  if ( this->initialized ) {

    return parent->restoreGeometry ( this->userConfig->getSettings ()->value ( "geometry" ).toByteArray () );

  } else {

    qDebug () << "La clase AppInit no ha sido inicializa correctamente.";
    return false;
  }
}

bool AppInit::restoreState ( QMainWindow *parent ) {

  if ( this->initialized ) {

    return parent->restoreState ( this->userConfig->getSettings ()->value ( "windowState" ).toByteArray () );

  } else {

    qDebug () << "La clase AppInit no ha sido inicializa correctamente.";
    return false;
  }
}
