#include "RegisterClasses.h"


RegisterClasses::RegisterClasses () {}

void RegisterClasses::addTypeClass () {

  qRegisterMetaType<CommandProcessor>( "CommandProcessor" );
  qRegisterMetaType<TypeCmd>( "TypeCmd" );
}
