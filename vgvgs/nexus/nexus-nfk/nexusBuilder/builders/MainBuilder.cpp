#include "MainBuilder.h"


using namespace NSLIB_BUILDER;


MainBuilder::MainBuilder ( QObject *parent ) : QObject ( parent ) {}

QString MainBuilder::build ( QString resource, NexusBuilder::ProjectId projectType ) {

  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  QStringList codeLines = NexusBuilderUtils::stringToLines ( fileContent );
  int index = -1;
  index = codeLines.indexOf ( "// External Libraries" );
  codeLines.insert ( index + 1, "#include \"appsystem/AppManager.h\"" );
  switch ( projectType ) {

    case NexusBuilder::ProjectId::CONSOLE :

      index = codeLines.indexOf ( "// Internal Libraries" );
      codeLines.insert ( index + 1, "#include \"RegisterClasses.h\"" );

      index = codeLines.indexOf ( "int main ( int argc, char *argv [] ) {" );
      codeLines.insert ( index + 1, "" );
      codeLines.insert ( index + 2, "  NSLIB_CORE::AppManager::getInstance ()->createConsoleOnly ( argc, argv );" );
      codeLines.insert ( index + 3, "  NSLIB_CORE::AppManager::getInstance ()->initialize ();" );
      codeLines.insert ( index + 4, "  RegisterClasses::getInstance ()->addTypeClass ();" );
      codeLines.insert ( index + 5, "  return NSLIB_CORE::AppManager::getInstance ()->executeConsoleOnly ();" );
      break;

    case NexusBuilder::ProjectId::NEXUS :

      index = codeLines.indexOf ( "// Internal Libraries" );
      codeLines.insert ( index + 1, "#include \"MainWindow.h\"" );
      codeLines.insert ( index + 2, "#include \"RegisterClasses.h\"" );

      index = codeLines.indexOf ( "int main ( int argc, char *argv [] ) {" );
      codeLines.insert ( index + 1, "" );
      codeLines.insert ( index + 2, "  NSLIB_CORE::AppManager::getInstance ()->create ( argc, argv );" );
      codeLines.insert ( index + 3, "  NSLIB_CORE::AppManager::getInstance ()->initialize ();" );
      codeLines.insert ( index + 4, "  RegisterClasses::getInstance ()->addTypeClass ();" );
      codeLines.insert ( index + 5, "  if ( NSLIB_CORE::AppManager::getInstance ()->isGuiApp () ) {" );
      codeLines.insert ( index + 6, "" );
      codeLines.insert ( index + 7, "    MainWindow w;" );
      codeLines.insert ( index + 8, "    return NSLIB_CORE::AppManager::getInstance ()->execute ( &w );" );
      codeLines.insert ( index + 9, "" );
      codeLines.insert ( index + 10, "  } else {" );
      codeLines.insert ( index + 11, "" );
      codeLines.insert ( index + 12, "    return NSLIB_CORE::AppManager::getInstance ()->execute ();" );
      codeLines.insert ( index + 13, "  }" );
      break;

    case NexusBuilder::ProjectId::GUI :
    case NexusBuilder::ProjectId::SIMPLEGUI :

      index = codeLines.indexOf ( "// Internal Libraries" );
      codeLines.insert ( index + 1, "#include \"MainWindow.h\"" );

      index = codeLines.indexOf ( "int main ( int argc, char *argv [] ) {" );
      codeLines.insert ( index + 1, "" );
      codeLines.insert ( index + 2, "  NSLIB_CORE::AppManager::getInstance ()->createGuiOnly ( argc, argv );" );
      codeLines.insert ( index + 3, "  NSLIB_CORE::AppManager::getInstance ()->initialize ();" );
      codeLines.insert ( index + 4, "  MainWindow w;" );
      codeLines.insert ( index + 5, "  return NSLIB_CORE::AppManager::getInstance ()->executeGuiOnly ( &w );" );
      break;
  }
  fileContent = codeLines.join ( "\n" );
  return fileContent;
}
