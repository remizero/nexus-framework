#include "ProBuilder.h"


using namespace NSLIB_BUILDER;


ProBuilder::ProBuilder ( QObject *parent ) : QObject ( parent ) {}

QString ProBuilder::build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource + "pro.template" );
  fileContent = NexusBuilderUtils::normalizeProjectFileContent ( fileContent, projectName, projectType );
  QStringList codeLines = NexusBuilderUtils::stringToLines ( fileContent );
  codeLines = NexusBuilderUtils::getClause ( codeLines, "SOURCES +=" );
  // TODO Como agregar módulos de Qt en el archivo .pro.
  // TODO Como agregar agregar los archivos a la clausula SOURCES.
  // TODO Como agregar agregar los archivos a la clausula HEADERS.
  // TODO Como agregar agregar los archivos a la clausula RESOURCES.
  // TODO Como agregar agregar los archivos a la clausula FORM.
  // TODO Como agregar agregar los archivos a la clausula DEF_FILE.
  // TODO Como agregar agregar los archivos a la clausula DISTFILES.
  // TODO Como agregar agregar los archivos a la clausula INCLUDEPATH.
  // TODO Como agregar agregar los archivos a la clausula DEPENDPATH.
  // TODO Como agregar agregar las librerías correspondientes al tipo de proyecto.
  fileContent = codeLines.join ( "\n" );
  return fileContent;
}
