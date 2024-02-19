#include "PublicProperty.h"

using namespace NSLIB_XSD;

PublicProperty::PublicProperty ( QString value ) {

  this->value = value;
}

PublicProperty::PublicProperty ( const PublicProperty & ) : PropertyAbs () {}

PublicProperty::~PublicProperty () {}

QString PublicProperty::getValue () const {

  return this->value;
}

void PublicProperty::setValue ( const QString &value ) {

  this->value = value;
}
