#include "ExportsBuilder.h"


using namespace NSLIB_BUILDER;


ExportsBuilder::ExportsBuilder ( QObject *parent ) : QObject ( parent ) {}

QString ExportsBuilder::build ( QString resource, const QStringList &resourceList ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  for ( const QString &resourceFile : resourceList ) {

    QStringList resourceFileSplit = resourceFile.split ( "/" );
    fileContent += QString ( "  qInitResources_" ) + resourceFileSplit.at ( resourceFileSplit.length () - 1 );
  }
  fileContent += QString ( "\n" );
  return fileContent;
}
