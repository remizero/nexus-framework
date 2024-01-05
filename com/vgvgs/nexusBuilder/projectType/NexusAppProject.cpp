#include "NexusAppProject.h"


using namespace NSLIB_BUILDER;


NexusAppProject::NexusAppProject ( QObject *parent ) : AppProject ( parent ) {}

void NexusAppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/nexus/";
}

// bool NexusAppProject::createProjectFiles () {

//   bool done = AppProject::createProjectFiles ();
//   if ( done ) {

//     if ( ( done = this->copyFiles ( {
//                                       "CommandProcessor.h",
//                                       "CommandProcessor.cpp",
//                                       "MainWindow.h",
//                                       "MainWindow.cpp",
//                                       "MainWindow.ui",
//                                       "RegisterClasses.h",
//                                       "RegisterClasses.cpp"
//                                     }, this->resource ) ) ) {

//       done = this->copyFiles ( {
//                                  "Command.h",
//                                  "Command.cpp"
//                                }, this->resource + "commands/", "commands" );
//     }
//   }
//   return done;
// }

// bool NexusAppProject::createDirStruct () {

//   bool done = AppProject::createDirStruct ();
//   if ( done ) {

//     done = this->createDir ( { "commands" } );
//   }
//   return done;
// }
