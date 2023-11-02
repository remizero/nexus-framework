#include "ConfigAbs.h"


using namespace NAMESPACE_LIBRARY_CORE;


ConfigAbs::ConfigAbs () {}

QSettings *ConfigAbs::getSettings () const {

  return this->settings;
}
