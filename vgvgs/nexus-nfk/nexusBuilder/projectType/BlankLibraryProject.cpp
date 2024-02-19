#include "BlankLibraryProject.h"


using namespace NSLIB_BUILDER;


BlankLibraryProject::BlankLibraryProject ( QObject *parent ) : LibraryProject ( parent ) {}

void BlankLibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projectType, verboseMode );
  this->resource = ":/projects/resources/library/plugin/";
}
