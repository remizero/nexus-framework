#include "NexusProject.h"


using namespace NSLIB_NEXUSBUILDER;


NexusProject::NexusProject () {}

void NexusProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/nexus/";
}

bool NexusProject::createProjectFiles () {

  bool done = AppProject::createProjectFiles ();
  if ( done ) {

    if ( ( done = this->copyFiles ( {
                                      "CommandProcessor.h",
                                      "CommandProcessor.cpp",
                                      "MainWindow.h",
                                      "MainWindow.cpp",
                                      "MainWindow.ui",
                                      "RegisterClasses.h",
                                      "RegisterClasses.cpp"
                                    }, this->resource ) ) ) {

      done = this->copyFiles ( {
                                 "Command.h",
                                 "Command.cpp"
                               }, this->resource + "commands/", "commands" );
    }
  }
  return done;
}

bool NexusProject::createDirStruct () {

  bool done = AppProject::createDirStruct ();
  if ( done ) {

    done = this->createDir ( { "commands" } );
  }
  return done;
}
