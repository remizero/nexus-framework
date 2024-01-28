#include "SubstitutionGroupProperty.h"

using namespace NSLIB_XSD;

SubstitutionGroupProperty::SubstitutionGroupProperty ( bool value ) {

  this->value = value;
}

SubstitutionGroupProperty::SubstitutionGroupProperty ( const SubstitutionGroupProperty & ) : PropertyAbs () {}

SubstitutionGroupProperty::~SubstitutionGroupProperty () {}

bool SubstitutionGroupProperty::getValue () const {

  return this->value;
}

void SubstitutionGroupProperty::setValue ( bool value ) {

  this->value = value;
}
