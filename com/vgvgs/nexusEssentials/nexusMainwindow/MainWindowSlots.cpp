#include "MainWindowSlots.h"

#include <QDebug>

using namespace NSLIB_MAINWINDOW;

MainWindowSlots::MainWindowSlots ( QMainWindow *parent ) {

  this->parent = parent;
}

void MainWindowSlots::slotReboot () {

  qDebug () << "Performing application reboot...";
  qApp->exit ( NSLIB_CORE::App::EXIT_CODE_REBOOT );
}
