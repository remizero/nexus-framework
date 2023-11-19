#include "cmdNameIdentifier.h"

cmdNameIdentifier::cmdNameIdentifier () {

  notImplemented(); // TODO Eliminar esta macro. Si no requiere inicialización personalizada, puede dejarlo en blanco.
}

QCommandLineOption cmdNameIdentifier::commandOption () const {

  notImplemented(); // TODO Eliminar esta macro. Debe ajustar los valores para la línea de comando personalizada.
  return QCommandLineOption ( { "shortFlag", "longFlag" }, "Description Flag.", "argumentFlag", "defaultValueFlag" );
}

QString cmdNameIdentifier::description () const {

  notImplemented(); // TODO Eliminar esta macro. Debe ajustar los valores para la línea de comando personalizada.
  return "Description Flag.";
}

void cmdNameIdentifier::execute () {

  notImplemented(); // TODO Eliminar esta macro. Si no requiere implementación personalizada, puede dejarlo en blanco.
}

QString cmdNameIdentifier::name () const {

  return "longFlag"; // TODO Eliminar esta macro. Debe ajustar los valores para la línea de comando personalizada.
}
