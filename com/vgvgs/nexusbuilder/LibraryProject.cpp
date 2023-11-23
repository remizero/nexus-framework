#include "LibraryProject.h"


using namespace NSLIB_NEXUSBUILDER;


LibraryProject::LibraryProject () {}

void LibraryProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projecType, verboseMode );
}

bool LibraryProject::createProjectFiles () {

  return this->copyFiles ( {
                             "Version.h",
                             "Version.cpp"
                           }, this->resource );
}
