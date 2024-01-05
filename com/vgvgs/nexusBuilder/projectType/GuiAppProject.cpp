#include "GuiAppProject.h"


using namespace NSLIB_BUILDER;


GuiAppProject::GuiAppProject ( QObject *parent ) : AppProject ( parent ) {}

void GuiAppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/gui/";
}

// bool GuiAppProject::createProjectFiles () {

//   bool done = AppProject::createProjectFiles ();
//   if ( done ) {

//     done = this->copyFiles ( {
//                                 "MainWindow.h",
//                                 "MainWindow.cpp",
//                                 "MainWindow.ui"
//                               }, this->resource );
//   }
//   return done;
// }
