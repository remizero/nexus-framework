#include "GuiProject.h"


using namespace NSLIB_NEXUSBUILDER;


GuiProject::GuiProject () {}

void GuiProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/gui/";
}

bool GuiProject::createProjectFiles () {

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
