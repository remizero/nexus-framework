#include "BlankAppProject.h"


using namespace NSLIB_BUILDER;


BlankAppProject::BlankAppProject ( QObject *parent ) : AppProject ( parent ) {}

void BlankAppProject::init ( QString projectName, QString projectPath, QString projecType, bool verboseMode ) {

  AppProject::init ( projectName, projectPath, projecType, verboseMode );
}
