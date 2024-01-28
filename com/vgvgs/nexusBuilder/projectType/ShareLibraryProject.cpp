#include "ShareLibraryProject.h"


using namespace NSLIB_BUILDER;


ShareLibraryProject::ShareLibraryProject ( QObject *parent ) : LibraryProject ( parent ) {}

void ShareLibraryProject::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  LibraryProject::init ( projectName, projectPath, projectType, verboseMode );
  this->dirList << "resources";
  this->projectFileList << "global.h.template"
                        << "Version.h.template"
                        << "Version.cpp.template"
                        << "resources.qrc.template"
                        << "export.def.template";
}
