#include "PluginProject.h"


using namespace NSLIB_BUILDER;


PluginProject::PluginProject () {}

void PluginProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/library/plugin/";
}

bool PluginProject::createProjectFiles () {

  bool done = LibraryProject::createProjectFiles ();
  if ( done ) {

    done = this->copyFiles ( {
                               "Plugin.h",
                               "Plugin.cpp",
                               "Plugin.json",
                               "Plugin_global.h"
                             }, this->resource );
  }
  return done;
}
