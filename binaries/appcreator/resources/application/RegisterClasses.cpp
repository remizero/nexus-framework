#include "RegisterClasses.h"


RegisterClasses::RegisterClasses () {}

void RegisterClasses::addTypeClass () {

  qRegisterMetaType<CommandProcessor>( "CommandProcessor" ); // TODO No modificar.
  notImplemented(); // TODO Eliminar esta macro. Si no requiere implementación personalizada, puede dejarlo en blanco.
}
