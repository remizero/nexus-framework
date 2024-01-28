#include "NillableProperty.h"

using namespace NSLIB_XSD;

NillableProperty::NillableProperty ( bool value ) {

  this->value = value;
}

NillableProperty::NillableProperty ( const NillableProperty & ) : PropertyAbs () {}

NillableProperty::~NillableProperty () {}

bool NillableProperty::getValue () const {

  return this->value;
}

void NillableProperty::setValue ( bool value ) {

  this->value = value;
}
