#include "AttributeBuilder.h"


using namespace NSLIB_BUILDER;


AttributeBuilder::AttributeBuilder () {}

QString AttributeBuilder::build () {

  QString attribute = ParamBuilder::build ();
  attribute += ";";
  return attribute;
}

const QString &AttributeBuilder::getAccessibility () const {

  return this->accessibility;
}

void AttributeBuilder::setAccessibility ( const QString &newAccessibility ) {

  this->accessibility = newAccessibility;
}
