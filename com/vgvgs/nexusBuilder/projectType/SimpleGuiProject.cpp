#include "SimpleGuiProject.h"


using namespace NSLIB_BUILDER;


SimpleGuiProject::SimpleGuiProject () {}

void SimpleGuiProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/simplegui/";
}

bool SimpleGuiProject::createProjectFiles () {

  bool done = AppProject::createProjectFiles ();
  if ( done ) {

    done = this->copyFiles ( {
                                "MainWindow.h",
                                "MainWindow.cpp",
                                "MainWindow.ui"
                              }, this->resource );
  }
  return done;
}
