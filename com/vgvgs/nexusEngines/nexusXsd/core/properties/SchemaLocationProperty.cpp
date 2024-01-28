#include "SchemaLocationProperty.h"

using namespace NSLIB_XSD;

SchemaLocationProperty::SchemaLocationProperty ( bool value ) {

  this->value = value;
}

SchemaLocationProperty::SchemaLocationProperty ( const SchemaLocationProperty & ) : PropertyAbs () {}

SchemaLocationProperty::~SchemaLocationProperty () {}

bool SchemaLocationProperty::getValue () const {

  return this->value;
}

void SchemaLocationProperty::setValue ( bool value ) {

  this->value = value;
}
