#include "NexusMainWindowActions.h"

using namespace NSLIB_MAINWINDOW;

NexusMainWindowActions::NexusMainWindowActions ( QMainWindow *parent ) {

  this->parent = parent;
}

NexusMainWindowActions::~NexusMainWindowActions () {}

QMainWindow *NexusMainWindowActions::getParent () const {

  return this->parent;
}

void NexusMainWindowActions::loadBasicActions () {}

void NexusMainWindowActions::loadPluginActions () {}

void NexusMainWindowActions::setPluginAction () {}
