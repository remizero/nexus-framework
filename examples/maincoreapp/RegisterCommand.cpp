#include "RegisterCommand.h"


RegisterCommand::RegisterCommand () {}

void RegisterCommand::addTypeCommand () {

  qRegisterMetaType<InfoCmd>( "InfoCmd" );
}
