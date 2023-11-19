#include "NexusProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//NexusProject::NexusProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  AppProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/app/nexus/";
//}
NexusProject::NexusProject () {}

bool NexusProject::create () {

  return AppProject::create ();
}

void NexusProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/nexus/";
}

bool NexusProject::createProjectFiles () {

  return AppProject::createProjectFiles ();
}
