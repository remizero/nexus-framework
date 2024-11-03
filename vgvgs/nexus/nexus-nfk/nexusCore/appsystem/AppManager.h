#ifndef APPMANAGER_H
#define APPMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/App.h"
#include "appsystem/AppConfig.h"
#include "appsystem/AppExit.h"
#include "appsystem/AppInit.h"
#include "appsystem/AppPaths.h"
#include "appsystem/AppUtils.h"
#include "appsystem/UserConfig.h"
#include "commandsystem/CommandManager.h"
#include "loggersystem/Logger.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QTimer>

// Librerías C++
// C++ Libraries


/**
 * Integración en la aplicación GUI
 * Para lograr esta dualidad de comportamientos en GUI y consola, la arquitectura
 * debería considerar lo siguiente:
 *
 * TODO 1-. Detección del modo de ejecución:
 *          AppManager o una clase similar puede detectar si la aplicación fue
 *          iniciada con argumentos de consola específicos (como -no-gui o un
 *          comando particular) y, en consecuencia, decidir si cargar el entorno
 *          gráfico completo o ejecutar solo el comando.
 * TODO 2-. Inicialización controlada:
 *          Solo carga componentes de GUI (como QMainWindow) si no se han
 *          detectado comandos de consola o si se indica explícitamente que se
 *          quiere el modo GUI.
 * TODO 3-. Comportamiento híbrido:
 *          Permite que ciertos comandos se ejecuten en segundo plano incluso si
 *          el entorno gráfico está activo. Esto es útil, por ejemplo, si un
 *          usuario quiere hacer configuraciones desde consola mientras la GUI
 *          está en ejecución.
 */
namespace NS_VGVGS {

  namespace NS_NEXUS {

    namespace NS_CORE {

      class CORE_EXPORT AppManager : public QObject, public NSLIB_PATTERNIFY::Singleton<AppManager> {

          Q_OBJECT

        public :
          void create ( int &argc, char *argv [] );
          void createConsoleOnly ( int &argc, char *argv [] );
          void createGuiOnly ( int &argc, char *argv [] );
          int execute ( QMainWindow *mainWindow = nullptr );
          int executeConsoleOnly ();
          int executeGuiOnly ( QMainWindow *mainWindow );
          AppConfig *getAppConfig () const;
          UserConfig *getUserConfig () const;
          void initialize ();
          bool isGuiApp ();

        private :
                      bool initialized;
                 AppConfig *appConfig = nullptr;
                UserConfig *userConfig = nullptr;
          QCoreApplication *application;
          void cleanArg ( int &argc, char *argv [] );
          void setAppInfo ( QCoreApplication *application );
          AppManager ( QObject *parent = nullptr );
          friend class NSLIB_PATTERNIFY::Singleton<AppManager>;
      };
    }
  }
}

#endif // APPMANAGER_H
