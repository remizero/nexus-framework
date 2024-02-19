#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries
#include "PluginInfo.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QList>
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT PluginInterface : public QObject {

            Q_OBJECT

          public :
            // explicit PluginInterface ( QObject *parent = nullptr ) {}
            PluginInterface () {}
            virtual ~PluginInterface () {}

            virtual void initialize ( QJsonObject object ) = 0;
            virtual void finalize () = 0;
            virtual QAction menuAction () const = 0;
            virtual QList<QAction *> actions () const = 0;
            virtual PluginInfo *getPluginInfo () = 0;

          signals :

        };
      }
    }
  }

Q_DECLARE_INTERFACE ( NSLIB_CORE::PluginInterface, "com.vgvgs.core.PluginInterface" )

#endif // PLUGININTERFACE_H
