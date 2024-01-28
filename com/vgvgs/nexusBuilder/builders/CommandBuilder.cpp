#include "CommandBuilder.h"


using namespace NSLIB_BUILDER;


CommandBuilder::CommandBuilder ( QObject *parent ) : QObject ( parent ) {}

QString CommandBuilder::build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType ) {

  Q_UNUSED ( resource )
  Q_UNUSED ( projectName )
  Q_UNUSED ( projectType )
  return "";
}
