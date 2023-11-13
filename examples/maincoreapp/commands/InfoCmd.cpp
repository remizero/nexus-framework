#include "InfoCmd.h"


InfoCmd::InfoCmd () {}

QCommandLineOption InfoCmd::commandOption () const {

  return QCommandLineOption ( "info", "Información de la aplicacion." );
}

QString InfoCmd::description () const {

  return "Información de la aplicacion.";
}

void InfoCmd::execute () {

  qInfo () << "Información de la aplicacion.";
}

QString InfoCmd::name () const {

  return "info";
}
