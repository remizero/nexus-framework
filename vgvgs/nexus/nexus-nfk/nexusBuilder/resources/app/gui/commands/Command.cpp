#include "{{Command}}.h"

{{Command}}::{{Command}} () {}

QCommandLineOption {{Command}}::commandOption () const {
  
  notImplemented();
  return QCommandLineOption ( { "optionShortName", "optionLongName"}, "Command Description.", "param", "defaultValue" );
}

QString {{Command}}::description () const {
  
  notImplemented();
  return "Command Description.";
}

void {{Command}}::execute () {

  notImplemented();
}

QString {{Command}}::name () const {
  
  notImplemented();
  return "optionLongName";
}
