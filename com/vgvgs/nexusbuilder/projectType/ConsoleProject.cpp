#include "ConsoleProject.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


//ConsoleProject::ConsoleProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) :
//  AppProject ( projectName, projectPath, projecType, verboseMode ) {

//  this->resource = ":/projects/resources/app/console/";
//}
ConsoleProject::ConsoleProject () {}

bool ConsoleProject::create () {

  return AppProject::create ();
}

void ConsoleProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
  this->resource = ":/projects/resources/app/console/";
}

bool ConsoleProject::createProjectFiles () {

  return AppProject::createProjectFiles ();
}
