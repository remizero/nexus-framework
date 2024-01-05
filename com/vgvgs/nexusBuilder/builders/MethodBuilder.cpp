#include "MethodBuilder.h"


using namespace NSLIB_BUILDER;


MethodBuilder::MethodBuilder () {}

QString MethodBuilder::build () {

  // TODO Como generar la definición en el archivo cabecera y la implementación en el archivo de implementación.
}

const QString &MethodBuilder::getAccessibility () const {

  return this->accessibility;
}

void MethodBuilder::setAccessibility ( const QString &newAccessibility ) {

  this->accessibility = newAccessibility;
}

bool MethodBuilder::getImplementedIn () const {

  return this->implementedIn;
}

void MethodBuilder::setImplementedIn ( bool newImplementedIn ) {

  this->implementedIn = newImplementedIn;
}
