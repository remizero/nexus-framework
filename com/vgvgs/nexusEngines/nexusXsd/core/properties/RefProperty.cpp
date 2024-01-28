#include "RefProperty.h"

using namespace NSLIB_XSD;

RefProperty::RefProperty ( QString value ) {

  this->value = value;
}

RefProperty::RefProperty ( const RefProperty & ) : PropertyAbs () {}

RefProperty::~RefProperty () {}

QString RefProperty::getValue () const {

  return this->value;
}

void RefProperty::setValue ( const QString &value ) {

  this->value = value;
}
