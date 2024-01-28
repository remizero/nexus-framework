#include "FunctionBuilder.h"


using namespace NSLIB_BUILDER;


FunctionBuilder::FunctionBuilder () {

  this->pointer = false;
}

QString FunctionBuilder::build ( NexusBuilder::TypeBuild typeBuild, QString memberScope ) {

  this->createDefinition ( typeBuild, memberScope );
  if ( typeBuild == NexusBuilder::TypeBuild::IMPLEMENTATION ) {

    // TODO Normalizar el body de la función.
    this->function += this->body;
    this->function += "\n}";
  }
  return this->function;
}

void FunctionBuilder::createDefinition ( NexusBuilder::TypeBuild typeBuild, QString memberScope ) {

  this->function += this->type + " ";
  this->function += this->isPointer () ? "*" : "";
  this->createSectionedDefinition ( typeBuild, memberScope );
  this->createParams ();
  this->function += ")";
  this->createSectionedDefinition ( typeBuild, memberScope, false );
}

void FunctionBuilder::createParams () {

  if ( this->paramList.count () > 0 ) {

    this->function += " ";
    for ( int i = 0; i < this->paramList.size (); ++i ) {

      this->paramList.at ( i )->build ();
      this->function += this->paramList.at ( i )->getParam ();
      if ( i < paramList.size () - 1 ) {

        this->function += ", ";
      }
    }
    this->function += " ";
  }
}

void FunctionBuilder::createSectionedDefinition ( NexusBuilder::TypeBuild typeBuild, QString memberScope, bool begin ) {

  if ( typeBuild == NexusBuilder::TypeBuild::DEFINITION ) {

    if ( begin ) {

      this->function += this->name + " (";

    } else {

      this->function += ";";
    }
  } else if ( typeBuild == NexusBuilder::TypeBuild::IMPLEMENTATION ) {

    if ( begin ) {
      if ( memberScope.isEmpty () ) {

        this->function += this->name + " (";

      } else {

        this->function += memberScope + "::" + this->name + " (";
      }
    } else {

      this->function += " {\n\n";
    }
  }
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

bool FunctionBuilder::isPointer () const {

  return this->pointer;
}

void FunctionBuilder::setFunction ( const QString &newFunction ) {

  this->function = newFunction;
}

void FunctionBuilder::setIsPointer ( bool newIsPointer ) {

  this->pointer = newIsPointer;
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
