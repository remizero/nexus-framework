#include "ShareLibraryProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//ShareLibraryProject::ShareLibraryProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  LibraryProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/library/share/";
//}
ShareLibraryProject::ShareLibraryProject () {}

bool ShareLibraryProject::create () {

  return LibraryProject::create ();
}

void ShareLibraryProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/library/share/";
}

bool ShareLibraryProject::createProjectFiles () {

  return LibraryProject::createProjectFiles ();
}
