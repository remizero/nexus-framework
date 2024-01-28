#include "TestProperty.h"

using namespace NSLIB_XSD;

TestProperty::TestProperty ( bool value ) {

  this->value = value;
}

TestProperty::TestProperty ( const TestProperty & ) : PropertyAbs () {}

TestProperty::~TestProperty () {}

bool TestProperty::getValue () const {

  return this->value;
}

void TestProperty::setValue ( bool value ) {

  this->value = value;
}
