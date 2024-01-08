#include "LibraryProject.h"


using namespace NSLIB_BUILDER;


LibraryProject::LibraryProject ( QObject *parent ) : ProjectAbs ( parent ) {}

void LibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projectType, verboseMode );
}

// bool LibraryProject::createProjectFiles () {

//   return this->copyFiles ( {
//                              "Version.h",
//                              "Version.cpp"
//                            }, this->resource );
// }
