#include "ConfigAbs.h"


using namespace NSLIB_CORE;


ConfigAbs::ConfigAbs () {}

QSettings *ConfigAbs::getSettings () const {

  return this->settings;
}
