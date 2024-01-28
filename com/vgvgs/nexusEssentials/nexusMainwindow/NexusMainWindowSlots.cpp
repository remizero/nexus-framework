#include "NexusMainWindowSlots.h"


using namespace NSLIB_MAINWINDOW;


NexusMainWindowSlots::NexusMainWindowSlots ( QMainWindow *parent ) {

  this->parent = parent;
}

NexusMainWindowSlots::~NexusMainWindowSlots () {}

QMainWindow *NexusMainWindowSlots::getParent () const {

  return this->parent;
}

void NexusMainWindowSlots::slotReboot () {

  qDebug () << "Performing application reboot...";
  qApp->exit ( NSLIB_CORE::App::EXIT_CODE_REBOOT );
}
