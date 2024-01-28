#include "SourceProperty.h"

using namespace NSLIB_XSD;

SourceProperty::SourceProperty ( bool value ) {

  this->value = value;
}

SourceProperty::SourceProperty ( const SourceProperty & ) : PropertyAbs () {}

SourceProperty::~SourceProperty () {}

bool SourceProperty::getValue () const {

  return this->value;
}

void SourceProperty::setValue ( bool value ) {

  this->value = value;
}
