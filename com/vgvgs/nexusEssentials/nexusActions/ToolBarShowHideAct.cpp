#include "ToolBarShowHideAct.h"


using namespace NSLIB_ACTIONS;


ToolBarShowHideAct::ToolBarShowHideAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Quit );
}

void ToolBarShowHideAct::execAct () {

  // TODO: Determinar como obtener una o varias ToolBar pues pueden haber varias.
  /*if ( ( ( QMainWindow * ) this->myParent )->statusBar ()->isVisible () ) {

    ( ( QMainWindow * ) this->myParent )->statusBar ()->hide ();

  } else {

    ( ( QMainWindow * ) this->myParent )->statusBar ()->setVisible ( true );
  }*/
}
