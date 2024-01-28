#include "SettingsAct.h"


using namespace NSLIB_ACTIONS;


SettingsAct::SettingsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Preferences );
}

void SettingsAct::execAct () {

  NSLIB_XSDFORM::XsdDialog *xsdDialog = new NSLIB_XSDFORM::XsdDialog ( this->myParent );
  xsdDialog->getFormDialog ()->show ();
}
