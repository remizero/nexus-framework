#include "NamespaceProperty.h"

using namespace NSLIB_XSD;

NamespaceProperty::NamespaceProperty ( QString value ) {

  this->value = value;
}

NamespaceProperty::NamespaceProperty ( const NamespaceProperty & ) : PropertyAbs () {}

NamespaceProperty::~NamespaceProperty () {}

QString NamespaceProperty::getValue () const {

  return this->value;
}

void NamespaceProperty::setValue ( const QString &value ) {

  this->value = value;
}
