#include "ConsoleProject.h"


using namespace NSLIB_NEXUSBUILDER;


ConsoleProject::ConsoleProject () {}

void ConsoleProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/console/";
}

bool ConsoleProject::createProjectFiles () {

  bool done = AppProject::createProjectFiles ();
  if ( done ) {

    if ( ( done = this->copyFiles ( {
                                      "CommandProcessor.h",
                                      "CommandProcessor.cpp",
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

bool ConsoleProject::createDirStruct () {

  bool done = AppProject::createDirStruct ();
  if ( done ) {

    done = this->createDir ( { "commands" } );
  }
  return done;
}
