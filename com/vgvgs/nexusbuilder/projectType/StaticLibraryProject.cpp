#include "StaticLibraryProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//StaticLibraryProject::StaticLibraryProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  LibraryProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/library/static/";
//}
StaticLibraryProject::StaticLibraryProject () {}

bool StaticLibraryProject::create () {

  return LibraryProject::create ();
}

void StaticLibraryProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/library/static/";
}

bool StaticLibraryProject::createProjectFiles () {

  return LibraryProject::createProjectFiles ();
}
