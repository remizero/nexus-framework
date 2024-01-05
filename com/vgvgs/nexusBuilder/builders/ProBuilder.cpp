#include "ProBuilder.h"


using namespace NSLIB_BUILDER;


ProBuilder::ProBuilder () {}

QString ProBuilder::build ( QString resource ) {

  QString proTemplateFile = NexusBuilderUtils::loadProTemplate ( resource );
  QStringList proTemplateFileLines = NexusBuilderUtils::stringToLines ( proTemplateFile );
  proTemplateFileLines = NexusBuilderUtils::getClause ( proTemplateFileLines, "SOURCES +=" );
  // TODO Como agregar módulos de Qt en el archivo .pro.
  // TODO Como agregar el directorio base de los archivos .prf.
  // TODO Como agregar el nombre del proyecto en el archivo .pro.
  // TODO Como agregar el archivo projectConfiguration.prf según el tipo de proyecto.
  // TODO Como agregar agregar los archivos a la clausula SOURCES.
  // TODO Como agregar agregar los archivos a la clausula HEADERS.
  // TODO Como agregar agregar los archivos a la clausula RESOURCES.
  // TODO Como agregar agregar los archivos a la clausula FORM.
  // TODO Como agregar agregar los archivos a la clausula DEF_FILE.
  // TODO Como agregar agregar los archivos a la clausula DISTFILES.
  // TODO Como agregar agregar los archivos a la clausula INCLUDEPATH.
  // TODO Como agregar agregar los archivos a la clausula DEPENDPATH.
  // TODO Como agregar agregar las librerías correspondientes al tipo de proyecto.
  // TODO Como agregar el archivo copyFiles.prf según el tipo de proyecto.
  // TODO Como agregar el archivo deploymentRules.prf según el tipo de proyecto.
  // TODO Como convertir todo el QString contenedor de los valores a ajustar en archivo físico en el directorio del proyecto.
}
