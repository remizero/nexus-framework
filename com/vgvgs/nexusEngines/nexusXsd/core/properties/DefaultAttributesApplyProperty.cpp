#include "DefaultAttributesApplyProperty.h"

using namespace NSLIB_XSD;

DefaultAttributesApplyProperty::DefaultAttributesApplyProperty ( bool value ) {

  this->value = value;
}

DefaultAttributesApplyProperty::DefaultAttributesApplyProperty ( const DefaultAttributesApplyProperty & ) : PropertyAbs () {}

DefaultAttributesApplyProperty::~DefaultAttributesApplyProperty () {}

bool DefaultAttributesApplyProperty::getValue () const {

  return this->value;
}

void DefaultAttributesApplyProperty::setValue ( bool value ) {

  this->value = value;
}
