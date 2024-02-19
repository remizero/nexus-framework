#include "ProBuilder.h"


using namespace NSLIB_BUILDER;


ProBuilder::ProBuilder ( QObject *parent ) : QObject ( parent ) {}

QString ProBuilder::build ( QString projectPath, QString resource, const QString &projectName, NexusBuilder::ProjectId projectType ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource + "pro.template" );
  fileContent = NexusBuilderUtils::normalizeProjectFileContent ( fileContent, projectName, projectType );
  QStringList codeLines = NexusBuilderUtils::stringToLines ( fileContent );
  codeLines = NexusBuilderUtils::getClause ( codeLines, "SOURCES +=" );
  // TODO Como agregar módulos de Qt en el archivo .pro.
  // TODO Como agregar agregar los archivos a la clausula DEF_FILE.
  // TODO Como agregar agregar los archivos a la clausula DISTFILES.
  // TODO Como agregar agregar los archivos a la clausula INCLUDEPATH.
  // TODO Como agregar agregar los archivos a la clausula DEPENDPATH.
  // TODO Como agregar agregar las librerías correspondientes al tipo de proyecto.
  QStringList headersList = NexusBuilderUtils::findFiles ( projectPath, "*.h" );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "HEADERS += \\", headersList );
  QStringList sourcesList = NexusBuilderUtils::findFiles ( projectPath, "*.cpp" );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "SOURCES += \\", sourcesList );
  QStringList exportsList = NexusBuilderUtils::findFiles ( projectPath, "*.def" );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "DEF_FILE += \\", exportsList );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "DISTFILES += \\", exportsList );
  QStringList resourcesList = NexusBuilderUtils::findFiles ( projectPath, "*.qrc" );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "RESOURCES += \\", resourcesList );
  // QStringList xmlList = NexusBuilderUtils::findFiles ( projectPath, "*.xml" );
  // codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "SOURCES += \\", xmlList );
  QStringList formList = NexusBuilderUtils::findFiles ( projectPath, "*.ui \\" );
  codeLines = NexusBuilderUtils::insertLinesFromList ( codeLines, "FORM +=", formList );

  fileContent = codeLines.join ( "\n" );
  return fileContent;
}
