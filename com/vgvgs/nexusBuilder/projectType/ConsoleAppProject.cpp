#include "ConsoleAppProject.h"


using namespace NSLIB_BUILDER;


ConsoleAppProject::ConsoleAppProject ( QObject *parent ) : AppProject ( parent ) {}

void ConsoleAppProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projectType, verboseMode );
  this->dirList << "commands" << "resources";
  this->projectFileList << "main.cpp.template"
                        << "config.xml.template"
                        << "CommandProcessor.h.template"
                        << "CommandProcessor.cpp.template"
                        << "RegisterClasses.h.template"
                        << "RegisterClasses.cpp.template";
}
