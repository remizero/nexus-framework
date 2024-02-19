#include "NexusMainWindowSignals.h"


using namespace NSLIB_MAINWINDOW;


NexusMainWindowSignals::NexusMainWindowSignals ( QMainWindow *parent ) {

  this->parent = parent;
}

NexusMainWindowSignals::~NexusMainWindowSignals () {}

QMainWindow *NexusMainWindowSignals::getParent () const {

  return this->parent;
}
