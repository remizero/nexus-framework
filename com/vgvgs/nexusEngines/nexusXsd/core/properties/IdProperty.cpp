#include "IdProperty.h"

using namespace NSLIB_XSD;

IdProperty::IdProperty ( QString value ) {

  this->value = value;
}

IdProperty::IdProperty ( const IdProperty & ) : PropertyAbs () {}

IdProperty::~IdProperty () {}

QString IdProperty::getValue () const {

  return this->value;
}

void IdProperty::setValue ( const QString &value ) {

  this->value = value;
}
