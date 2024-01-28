#include "VersionBuilder.h"


using namespace NSLIB_BUILDER;


VersionBuilder::VersionBuilder ( QObject *parent ) : QObject ( parent ) {}

QString VersionBuilder::build ( QString resource, QString prefix, QString fileName ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  if ( fileName.contains ( ".h" ) ) {

    fileContent.replace ( "{{global.h}}", NexusBuilderUtils::normalizeGlobalName ( prefix, fileName ) );

  } else if ( fileName.contains ( ".cpp" ) ) {

    fileContent.replace ( "{{export}}", NexusBuilderUtils::normalizeExportName ( prefix ) );
  }
  return fileContent;
}
