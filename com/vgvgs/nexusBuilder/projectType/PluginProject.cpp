#include "PluginProject.h"


using namespace NSLIB_BUILDER;


PluginProject::PluginProject ( QObject *parent ) : LibraryProject ( parent ) {}

void PluginProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projectType, verboseMode );
  this->resource = ":/projects/resources/library/plugin/";
}

// bool PluginProject::createProjectFiles () {

//   bool done = LibraryProject::createProjectFiles ();
//   if ( done ) {

//     done = this->copyFiles ( {
//                                "Plugin.h",
//                                "Plugin.cpp",
//                                "Plugin.json",
//                                "Plugin_global.h"
//                              }, this->resource );
//   }
//   return done;
// }
