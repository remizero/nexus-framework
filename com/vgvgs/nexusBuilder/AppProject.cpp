#include "AppProject.h"


using namespace NSLIB_BUILDER;


AppProject::AppProject ( QObject *parent ) : ProjectAbs ( parent ) {}

void AppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  ProjectAbs::init ( projectName, projectPath, projecType, verboseMode );
}

// bool AppProject::createProjectDir () {

//   return ProjectAbs::createProjectDir ();
// }

// bool AppProject::createProjectFiles () {

//   bool done = false;
//   if ( ( done = this->copyFiles ( {
//                                     "main.cpp",
//                                     "export.def",
//                                     "resources.qrc"
//                                   }, this->resource ) ) ) {

//     done = this->copyFiles ( {
//                                "config.xml"
//                              }, this->resource + "resources/", "resources" );
//   }
//   return done;
// }

// bool AppProject::createDirStruct () {

//   return this->createDir ( { "resources" } );
// }
