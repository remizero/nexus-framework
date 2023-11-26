#include "PluginDependenciesInfo.h"


using namespace NSLIB_CORE;


const QString &PluginDependenciesInfo::getName () const {

  return this->name;
}

void PluginDependenciesInfo::setName ( const QString &newName ) {

  this->name = newName;
}

const QString &PluginDependenciesInfo::getVersion () const {

  return this->version;
}

void PluginDependenciesInfo::setVersion ( const QString &newVersion ) {

  this->version = newVersion;
}
