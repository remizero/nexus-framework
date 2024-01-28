#include "AttributeBuilder.h"


using namespace NSLIB_BUILDER;




AttributeBuilder::AttributeBuilder ( QString paramName, QString paramType, bool paramDynamic, bool paramNullPointer, QString paramDefaultValue )
  : ParamBuilder ( paramName, paramType, paramDynamic, paramNullPointer, paramDefaultValue )
  {}

void AttributeBuilder::build () {

  ParamBuilder::build ();
  this->param += ";";
}

NexusBuilder::Accessibility AttributeBuilder::getAccessibility () {

  return this->accessibility;
}

const NexusBuilder::GetterAndSetter &AttributeBuilder::getGetterAndSetter () const {

  return this->getterAndSetter;
}

void AttributeBuilder::setAccessibility ( NexusBuilder::Accessibility newAccessibility ) {

  this->accessibility = newAccessibility;
}

void AttributeBuilder::setGetterAndSetter ( const NexusBuilder::GetterAndSetter &newGetterAndSetter ) {

  this->getterAndSetter = newGetterAndSetter;
}
