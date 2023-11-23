#include "StaticLibraryProject.h"


using namespace NSLIB_NEXUSBUILDER;


StaticLibraryProject::StaticLibraryProject () {}

void StaticLibraryProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/library/static/";
}

bool StaticLibraryProject::createProjectFiles () {

  return LibraryProject::createProjectFiles ();
}
