#include "ConsoleAppProject.h"


using namespace NSLIB_BUILDER;


ConsoleAppProject::ConsoleAppProject ( QObject *parent ) : AppProject ( parent ) {}

void ConsoleAppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/templates/resources/projects/";
}

// bool ConsoleAppProject::createProjectDir () {

//   return AppProject::createProjectDir ();
// }

// bool ConsoleAppProject::createProjectFiles () {

//   bool done = AppProject::createProjectFiles ();
//   if ( done ) {

//     if ( ( done = this->copyFiles ( {
//                                       "CommandProcessor.h",
//                                       "CommandProcessor.cpp",
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

// bool ConsoleAppProject::createDirStruct () {

//   bool done = AppProject::createDirStruct ();
//   if ( done ) {

//     done = this->createDir ( { "commands" } );
//   }
//   return done;
// }
