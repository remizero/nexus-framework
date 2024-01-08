#include "GuiAppProject.h"


using namespace NSLIB_BUILDER;


GuiAppProject::GuiAppProject ( QObject *parent ) : AppProject ( parent ) {}

void GuiAppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projectType, verboseMode );
  this->dirList << "resources";
  this->projectFileList << "main.cpp.template"
                        << "config.xml.template"
                        << "MainWindow.h.template"
                        << "MainWindow.cpp.template";
}
