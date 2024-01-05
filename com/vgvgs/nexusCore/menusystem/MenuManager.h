#ifndef MENUMANAGER_H
#define MENUMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppPaths.h"
#include "pluginsystem/PluginAbs.h"
#include "pluginsystem/PluginActionInfo.h"
#include "pluginsystem/PluginActionLocationInfo.h"
#include "pluginsystem/PluginDependenciesInfo.h"
#include "pluginsystem/PluginInfo.h"
#include "pluginsystem/PluginInterface.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QMap>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QtWidgets/QToolBar>
#include <QVariant>

// Librerías C++
// C++ Libraries
#include <exception>


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT MenuManager : public QObject, public NSLIB_PATTERNIFY::Singleton<MenuManager> {

            Q_OBJECT

          public :
            enum MenuBarType {

              Standard,
              Stripe
            };
            void createMenuBar ( MenuBarType menuBarType = MenuBarType::Standard );
            void createToolbar ();
            void addActionToMenu ( const QString &menuName, QAction *action );
            void addActionToToolbar ( const QString &toolbarName, QAction *action );
            QMenu *findMenuByName ( const QString &menuName );
            QToolBar *findToolbarByName ( const QString &toolbarName );

          private :
               QMap<QString, QMenu *> menus;
            QMap<QString, QToolBar *> toolbars;
                             QMenuBar *menuBar;
                          MenuBarType menuBarType;
                             QVariant prueba;
            MenuManager ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<MenuManager>;
        };
      }
    }
  }
}

#endif // MENUMANAGER_H
