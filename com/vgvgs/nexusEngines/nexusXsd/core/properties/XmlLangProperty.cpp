#include "XmlLangProperty.h"

using namespace NSLIB_XSD;

XmlLangProperty::XmlLangProperty ( bool value ) {

  this->value = value;
}

XmlLangProperty::XmlLangProperty ( const XmlLangProperty & ) : PropertyAbs () {}

XmlLangProperty::~XmlLangProperty () {}

bool XmlLangProperty::getValue () const {

  return this->value;
}

void XmlLangProperty::setValue ( bool value ) {

  this->value = value;
}
