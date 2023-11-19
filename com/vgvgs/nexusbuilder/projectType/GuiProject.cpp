#include "GuiProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//GuiProject::GuiProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  AppProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/app/gui/";
//}
GuiProject::GuiProject () {}

bool GuiProject::create () {

  return AppProject::create ();
}

void GuiProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/gui/";
}

bool GuiProject::createProjectFiles () {

  return AppProject::createProjectFiles ();
}
