#include "ParamBuilder.h"


using namespace NSLIB_BUILDER;


ParamBuilder::ParamBuilder ( const QString &paramName, const QString &paramType, bool paramDynamic, bool paramNullPointer, const QString &paramDefaultValue )
  : name ( paramName ),
    type ( paramType ),
    dynamic ( paramDynamic ),
    nullPointer ( paramNullPointer ),
    defaultValue ( paramDefaultValue ) {

  this->param = "";
}

void ParamBuilder::build () {

  this->param += this->type + " ";
  this->param += this->dynamic ? "*" : "";
  this->param += this->name;
  if ( this->nullPointer ) {

    this->param += " = nullptr";

  } else {

    if ( !this->defaultValue.isEmpty () ) {

      // TODO Como validar el valor de this->defaultValue a agregar dependiendo
      // del tipo de dato que representa this->type
      this->param += " = " + this->defaultValue;
    }
  }
}

const QString &ParamBuilder::getDefaultValue () const {

  return this->defaultValue;
}

const QString &ParamBuilder::getName () const {

  return this->name;
}

const QString &ParamBuilder::getParam () const {

  return this->param;
}

const QString &ParamBuilder::getType () const {

  return this->type;
}

bool ParamBuilder::isDynamic () const {

  return this->dynamic;
}

bool ParamBuilder::isNullPointer () const {

  return this->nullPointer;
}
