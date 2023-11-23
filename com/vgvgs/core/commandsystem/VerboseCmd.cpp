#include "VerboseCmd.h"


using namespace NSLIB_CORE;


VerboseCmd::VerboseCmd () {}

QCommandLineOption VerboseCmd::commandOption () const {

  return QCommandLineOption ( { "V", "verbose"}, "Enable verbose mode." );
}

QString VerboseCmd::description () const {

  return "Enable verbose mode.";
}

void VerboseCmd::execute () {

  qInfo () << "Información de la aplicacion.";
}

QString VerboseCmd::name () const {

  return "verbose";
}
