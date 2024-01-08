#include "ClassBuilder.h"


using namespace NSLIB_BUILDER;


ClassBuilder::ClassBuilder () {}

QString ClassBuilder::build () {

  // TODO Como agregar las librerías requeridas?
  // TODO Como agregar la definición de clase?
  // TODO Como crear los namespace?
  // TODO Como crear los atributos?
  // TODO Como crear los métodos?
  // TODO Como crear los atributos y métodos según su accesibilidad?
  return "";
}

const QList<AttributeBuilder *> &ClassBuilder::getAttributeList () const {

  return this->attributeList;
}

void ClassBuilder::setAttributeList ( AttributeBuilder *attribute ) {

  this->attributeList.append ( attribute );
  // qSort ( this->attributeList.begin (), this->attributeList.end (),
  std::sort ( this->attributeList.begin (), this->attributeList.end (),
    [] ( const AttributeBuilder *a, const AttributeBuilder *b ) {

      return a->getName ().compare ( b->getName (), Qt::CaseInsensitive ) < 0;
    }
  );
}

const QList<MethodBuilder *> &ClassBuilder::getMethodList () const {

  return this->methodList;
}

void ClassBuilder::setMethodList ( MethodBuilder *method ) {

  this->methodList.append ( method );
  // qSort ( this->methodList.begin (), this->methodList.end (),
  std::sort ( this->methodList.begin (), this->methodList.end (),
    [] ( const MethodBuilder *a, const MethodBuilder *b ) {

      return a->getName ().compare ( b->getName (), Qt::CaseInsensitive ) < 0;
    }
  );
}

const QList<QString *> &ClassBuilder::getNamespaceList () const {

  return this->namespaceList;
}

void ClassBuilder::setNamespaceList ( QString *nameSpace ) {

  this->namespaceList.append ( nameSpace );
}
