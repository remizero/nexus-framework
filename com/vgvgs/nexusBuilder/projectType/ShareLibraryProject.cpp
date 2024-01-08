#include "ShareLibraryProject.h"


using namespace NSLIB_BUILDER;


ShareLibraryProject::ShareLibraryProject ( QObject *parent ) : LibraryProject ( parent ) {}

void ShareLibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projectType, verboseMode );
  this->resource = ":/projects/resources/library/share/";
}

// bool ShareLibraryProject::createProjectFiles () {

//   bool done = LibraryProject::createProjectFiles ();
//   if ( done ) {

//     done = this->copyFiles ( {
//                                "Share_global.h"
//                              }, this->resource );
//   }
//   return done;
// }
