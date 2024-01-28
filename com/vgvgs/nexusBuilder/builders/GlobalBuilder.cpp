#include "GlobalBuilder.h"


using namespace NSLIB_BUILDER;


GlobalBuilder::GlobalBuilder ( QObject *parent ) : QObject ( parent ) {}

QString GlobalBuilder::build ( QString resource , QString projectName ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  fileContent.replace ( "{{include_guard}}", projectName.toUpper () );
  fileContent.replace ( "{{namespace}}", projectName.at ( 0 ).toUpper () + projectName.mid ( 1 ) );
  return fileContent;
}
