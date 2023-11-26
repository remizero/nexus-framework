#include "NexusBuilderManager.h"


using namespace NSLIB_BUILDER;


NexusBuilderManager::NexusBuilderManager () {

  this->nexusBuilder = new NexusBuilder ();
  this->projectDirector = new ProjectDirector ();
}

void NexusBuilderManager::createProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  ProjectInterface *project = nexusBuilder->create ( NexusBuilder::stringToProjectId ( projecType ) );
  project->init ( projectName, projectPath, projecType, verboseMode );
  this->projectDirector->create ( project );
}
