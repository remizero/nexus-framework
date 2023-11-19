#include "PluginProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//PluginProject::PluginProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  LibraryProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/library/plugin/";
//}
PluginProject::PluginProject () {}

bool PluginProject::create () {

  return LibraryProject::create ();
}

void PluginProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/library/plugin/";
}

bool PluginProject::createProjectFiles () {

  return LibraryProject::createProjectFiles ();
}
