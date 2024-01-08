#include "ConfigBuilder.h"


using namespace NSLIB_BUILDER;


ConfigBuilder::ConfigBuilder ( QObject *parent ) : QObject ( parent ) {}

QString ConfigBuilder::build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType ) {

  return NexusBuilderUtils::loadFileContent ( resource );
}
