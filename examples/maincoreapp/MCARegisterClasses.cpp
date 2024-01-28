#include "MCARegisterClasses.h"


RegisterClasses::RegisterClasses () {}

void RegisterClasses::addTypeClass () {

  qRegisterMetaType<CommandProcessor>( "CommandProcessor" );
  qRegisterMetaType<InfoCmd>( "InfoCmd" );
  qRegisterMetaType<TypeCmd>( "TypeCmd" );
}
