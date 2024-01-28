#include "DefaultProperty.h"

using namespace NSLIB_XSD;

DefaultProperty::DefaultProperty ( QString value ) {

  this->value = value;
}

DefaultProperty::DefaultProperty ( const DefaultProperty &defaultProperty ) : PropertyAbs () {

  this->value = defaultProperty.getValue ();
}

DefaultProperty::~DefaultProperty () {}

QString DefaultProperty::getValue () const {

  return this->value;
}

void DefaultProperty::setValue ( const QString &value ) {

  this->value = value;
}
