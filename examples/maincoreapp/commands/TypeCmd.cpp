#include "TypeCmd.h"

TypeCmd::TypeCmd () {}

QCommandLineOption TypeCmd::commandOption () const {

  return QCommandLineOption ( { "t", "type"}, "Application type.", "type", "gui" );
}

QString TypeCmd::description () const {

  return "Application type.";
}

void TypeCmd::execute () {

  qInfo () << "Application type.";
}

QString TypeCmd::name () const {

  return "type";
}
