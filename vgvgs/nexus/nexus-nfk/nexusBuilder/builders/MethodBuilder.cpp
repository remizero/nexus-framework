#include "MethodBuilder.h"


using namespace NSLIB_BUILDER;


MethodBuilder::MethodBuilder () {}

QString MethodBuilder::build ( NexusBuilder::FileClasses fileClass, NexusBuilder::TypeBuild typeBuild, QString memberScope ) {

  // TODO Como generar la definición en el archivo cabecera y la implementación en el archivo de implementación.
    switch ( fileClass ) {

      case NexusBuilder::FileClasses::HEADERSONLY :

        qDebug () << "LÍNEA 16";
        return FunctionBuilder::build ( typeBuild, memberScope );
        break;

      case NexusBuilder::FileClasses::SOURCESONLY :

        // TODO Aquí obtener la primera línea y reconstruirla.
        qDebug () << "LÍNEA 23";
        return FunctionBuilder::build ( typeBuild, memberScope );
        break;

      default :

        switch ( typeBuild ) {

          case NexusBuilder::TypeBuild::DEFINITION :

            qDebug () << "LÍNEA 33";
            return FunctionBuilder::build ( typeBuild, memberScope );
            break;

          default :

            qDebug () << "LÍNEA 39";
            return FunctionBuilder::build ( typeBuild, memberScope );
            break;
        }
        break;
    }
    return "";
}

NexusBuilder::Accessibility MethodBuilder::getAccessibility () {

  return this->accessibility;
}

void MethodBuilder::setAccessibility ( NexusBuilder::Accessibility newAccessibility ) {

  this->accessibility = newAccessibility;
}

bool MethodBuilder::getImplementedIn () const {

  return this->implementedIn;
}

void MethodBuilder::setImplementedIn ( bool newImplementedIn ) {

  this->implementedIn = newImplementedIn;
}
