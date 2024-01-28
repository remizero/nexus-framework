#ifndef CLASSDEFINITION_H
#define CLASSDEFINITION_H

// Librerías Internas
// Internal Libraries
#include "CLASSNAME_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "pluginsystem/PluginAbs.h"
#include "pluginsystem/PluginInfo.h"
#include "pluginsystem/PluginInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


class CLASSDEFINITION_EXPORT CLASSNAME : public NSLIB_CORE::PluginInterface {

    Q_INTERFACES ( NSLIB_CORE::PluginInterface )
    Q_OBJECT
    Q_PLUGIN_METADATA ( IID "com.vgvgs.CLASSNAME" FILE "CLASSNAME.json" )

  public :
    CLASSNAME ();
    ~CLASSNAME () override;

    void initialize ( QJsonObject object ) override;
    void finalize () override;
    QAction menuAction () const override;
    QList<QAction *> actions () const override;
    NSLIB_CORE::PluginInfo *getPluginInfo () override;

  private :
    NSLIB_CORE::PluginInfo *pluginInfo;
};

#endif // CLASSDEFINITION_H
