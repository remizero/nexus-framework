#include "NexusAppProject.h"


using namespace NSLIB_BUILDER;


NexusAppProject::NexusAppProject ( QObject *parent ) : AppProject ( parent ) {}

void NexusAppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projectType, verboseMode );
  this->dirList << "commands" << "resources";
  this->projectFileList << "main.cpp.template"
                        << "config.xml.template"
                        << "CommandProcessor.h.template"
                        << "CommandProcessor.cpp.template"
                        << "export.def.template"
                        << "MainWindow.h.template"
                        << "MainWindow.cpp.template"
                        << "RegisterClasses.h.template"
                        << "RegisterClasses.cpp.template"
                        << "resources.qrc.template";
}
