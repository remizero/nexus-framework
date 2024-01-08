#include "StaticLibraryProject.h"


using namespace NSLIB_BUILDER;


StaticLibraryProject::StaticLibraryProject ( QObject *parent ) : LibraryProject ( parent ) {}

void StaticLibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projectType, verboseMode );
  this->resource = ":/projects/resources/library/static/";
}

// bool StaticLibraryProject::createProjectFiles () {

//   return LibraryProject::createProjectFiles ();
// }
