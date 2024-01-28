#include "ExportsBuilder.h"


using namespace NSLIB_BUILDER;


ExportsBuilder::ExportsBuilder ( QObject *parent ) : QObject ( parent ) {}

QString ExportsBuilder::build ( QString resource, const QStringList &resourceList ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  for ( const QString &resourceFile : resourceList ) {

    QStringList resourceFileSplit = resourceFile.split ( QDir::separator () );
    fileContent += QString ( "  qInitResources_" ) + resourceFileSplit.last ();
  }
  fileContent += QString ( "\n" );
  return fileContent;
}
