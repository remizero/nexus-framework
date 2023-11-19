#include "AppManager.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppManager::AppManager ( QObject *parent ) : QObject ( parent ) {

  this->application = nullptr;
  this->initialized = false;
}

void AppManager::cleanArg ( int &argc, char *argv [] ) {

  const char *toRemove = "-no-gui";
  int index = 1;
  while ( index < argc ) {

    if ( strcmp ( argv [ index ], toRemove ) == 0 ) {

      for ( int i = index; i < argc - 1; i++ ) {

        argv [ i ] = argv [ i + 1 ];
      }
      argc--;
    } else {

      index++;
    }
  }
}

void AppManager::create ( int &argc, char *argv [] ) {

  for ( int i = 1; i < argc; ++i ) {

    if ( qstrcmp ( argv [ i ], "-no-gui" ) ) {

      this->cleanArg ( argc, argv );
      this->application = new QCoreApplication ( argc, argv );
      break;
    }
  }
  if ( this->application == nullptr ) {

    this->application = new App ( argc, argv );
  }
}

int AppManager::execute ( QMainWindow *mainWindow ) {

  if ( this->initialized ) {

    QScopedPointer<QCoreApplication> appInstance ( this->application );
    Logger::getInstance ();

    this->setAppInfo ( appInstance.data () );
    if ( qobject_cast<QApplication *> ( appInstance.data () ) ) {
      // start GUI version...
      appInstance.data ()->addLibraryPath ( AppPaths::getInstance ()->getApplicationPluginsPath () );
      appInstance.data ()->addLibraryPath ( AppPaths::getInstance ()->getApplicationLibrariesPath () );
      AppInit::getInstance ()->initialize ( this->appConfig, this->userConfig );
      AppExit::getInstance ()->initialize ( this->appConfig, this->userConfig );
      mainWindow->show ();

    } else {
      // start non-GUI version...
      CommandManager::getInstance ()->setCustomCommands ( this->appConfig );
      CommandManager::getInstance ()->executeCommand ( appInstance.data () );
      QTimer::singleShot ( 1000, appInstance.data (), SLOT ( quit () ) );
    }
    return appInstance.data ()->exec ();

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente. Línea 76.";
    return 0;
  }
}

AppConfig *AppManager::getAppConfig () const {

  if ( this->initialized ) {

    return this->appConfig;

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente. Línea 89.";
    return nullptr;
  }
}

UserConfig *AppManager::getUserConfig () const {

  if ( this->initialized ) {

    return this->userConfig;

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente. Línea 102.";
    return nullptr;
  }
}

void AppManager::initialize () {

  AppPaths::getInstance ()->initialize ();
  this->appConfig = new AppConfig ();
  this->userConfig = new UserConfig ( this->appConfig->getSettings ()->value ( "app/userConfigFormat" ).toString () );
  CommandManager::getInstance ()->initialize ( this->appConfig );
  this->initialized = true;
}

bool AppManager::isGuiApp () {

  if ( this->initialized ) {

    return ( qobject_cast<QApplication *> ( this->application ) ) ? true : false;

  } else {

    qDebug () << "La clase AppManager no ha sido inicializa correctamente. Línea 124.";
    return false;
  }
}

void AppManager::setAppInfo ( QCoreApplication *application ) {

  application->setApplicationName    ( this->appConfig->getSettings ()->value ( "app/applicationname"    ).toString () );
  application->setApplicationVersion ( this->appConfig->getSettings ()->value ( "app/applicationversion" ).toString () );
  application->setOrganizationDomain ( this->appConfig->getSettings ()->value ( "app/organizationdomain" ).toString () );
  application->setOrganizationName   ( this->appConfig->getSettings ()->value ( "app/organizationname"   ).toString () );
  if ( QApplication *guiApp = qobject_cast<QApplication *> ( application ) ) {

    guiApp->setApplicationDisplayName ( this->appConfig->getSettings ()->value ( "app/applicationdisplayname" ).toString () );
  }
}
