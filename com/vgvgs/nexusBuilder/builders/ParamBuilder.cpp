#include "ParamBuilder.h"


using namespace NSLIB_BUILDER;


ParamBuilder::ParamBuilder () {}

QString ParamBuilder::build () {

  this->param += this->type + " " + this->name;
  if ( !this->defaultValue.isEmpty () ) {

    this->param += " = " + this->defaultValue;
  }
  return this->param;
}

const QString &ParamBuilder::getName () const {

  return this->name;
}

void ParamBuilder::setName ( const QString &newName ) {

  this->name = newName;
}

const QString &ParamBuilder::getParam () const {

  return this->param;
}

void ParamBuilder::setParam ( const QString &newParam ) {

  this->param = newParam;
}

const QString &ParamBuilder::getType () const {

  return this->type;
}

void ParamBuilder::setType ( const QString &newType ) {

  this->type = newType;
}

const QString &ParamBuilder::getDefaultValue () const {

  return this->defaultValue;
}

void ParamBuilder::setDefaultValue ( const QString &newDefaultValue ) {

  this->defaultValue = newDefaultValue;
}
