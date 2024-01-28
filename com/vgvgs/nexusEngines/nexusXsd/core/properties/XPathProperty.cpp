#include "XPathProperty.h"

using namespace NSLIB_XSD;

XPathProperty::XPathProperty ( bool value ) {

  this->value = value;
}

XPathProperty::XPathProperty ( const XPathProperty & ) : PropertyAbs () {}

XPathProperty::~XPathProperty () {}

bool XPathProperty::getValue () const {

  return this->value;
}

void XPathProperty::setValue ( bool value ) {

  this->value = value;
}
