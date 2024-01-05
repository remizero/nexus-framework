#include "FunctionBuilder.h"


using namespace NSLIB_BUILDER;


FunctionBuilder::FunctionBuilder () {}

QString FunctionBuilder::build () {

  this->function += this->type + " " + this->name + " (";
  if ( this->paramList.count () > 0 ) {

    this->function += " ";
    // TODO Procesar los parámetros.
    this->function += " ";

  }
  this->function += ")";
  this->function += " {\n\n";
  // TODO Normalizar el body de la función.
  this->function += this->body;
  this->function += "\n";
  this->function += "}";
  return this->function;
}

const QString &FunctionBuilder::getBody () const {

  return this->body;
}

void FunctionBuilder::setBody ( const QString &newBody ) {

  this->body = newBody;
}

const QString &FunctionBuilder::getFunction () const {

  return this->function;
}

void FunctionBuilder::setFunction ( const QString &newFunction ) {

  this->function = newFunction;
}

const QString &FunctionBuilder::getName () const {

  return this->name;
}

void FunctionBuilder::setName ( const QString &newName ) {

  this->name = newName;
}

const QString &FunctionBuilder::getType () const {

  return this->type;
}

void FunctionBuilder::setType ( const QString &newType ) {

  this->type = newType;
}

const QList<ParamBuilder *> &FunctionBuilder::getParamList () const {

  return this->paramList;
}

void FunctionBuilder::setParamList ( ParamBuilder *param ) {

  this->paramList.append ( param );
}
