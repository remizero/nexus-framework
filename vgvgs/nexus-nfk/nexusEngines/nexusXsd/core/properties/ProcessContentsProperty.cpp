#include "ProcessContentsProperty.h"

using namespace NSLIB_XSD;

ProcessContentsProperty::ProcessContentsProperty ( bool value ) {

  this->value = value;
}

ProcessContentsProperty::ProcessContentsProperty ( const ProcessContentsProperty & ) : PropertyAbs () {}

ProcessContentsProperty::~ProcessContentsProperty () {}

bool ProcessContentsProperty::getValue () const {

  return this->value;
}

void ProcessContentsProperty::setValue ( bool value ) {

  this->value = value;
}
