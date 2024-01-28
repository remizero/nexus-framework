#include "XPathDefaultNamespaceProperty.h"

using namespace NSLIB_XSD;

XPathDefaultNamespaceProperty::XPathDefaultNamespaceProperty ( bool value ) {

  this->value = value;
}

XPathDefaultNamespaceProperty::XPathDefaultNamespaceProperty ( const XPathDefaultNamespaceProperty & ) : PropertyAbs () {}

XPathDefaultNamespaceProperty::~XPathDefaultNamespaceProperty () {}

bool XPathDefaultNamespaceProperty::getValue () const {

  return this->value;
}

void XPathDefaultNamespaceProperty::setValue ( bool value ) {

  this->value = value;
}
