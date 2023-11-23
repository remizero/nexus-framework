#include "CLASSNAME.h"


Q_PLUGIN_METADATA ( IID "com.vgvgs.CLASSNAME" )


CLASSNAME::CLASSNAME () {

  this->pluginInfo = new NSLIB_CORE::PluginInfo ();
}

CLASSNAME::~CLASSNAME () {}

void CLASSNAME::initialize ( QJsonObject object ) {

  NSLIB_CORE::PluginAbs::initializeMetadata ( this->pluginInfo, object );
  notImplemented();
}

void CLASSNAME::finalize () {}

QAction CLASSNAME::menuAction () const {}

QList<QAction *> CLASSNAME::actions () const {}

NSLIB_CORE::PluginInfo *CLASSNAME::getPluginInfo () {

  return this->pluginInfo;
}
