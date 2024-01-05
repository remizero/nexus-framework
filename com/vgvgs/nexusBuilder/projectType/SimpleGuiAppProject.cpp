#include "SimpleGuiAppProject.h"


using namespace NSLIB_BUILDER;


SimpleGuiAppProject::SimpleGuiAppProject ( QObject *parent ) : AppProject ( parent ) {}

void SimpleGuiAppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/simplegui/";
}

// bool SimpleGuiAppProject::createProjectFiles () {

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
